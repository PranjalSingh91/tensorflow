/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/compiler/xla/python/pjrt_ifrt/xla_program_serdes.h"

#include <memory>
#include <utility>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "llvm/Support/Casting.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"  // from @llvm-project
#include "mlir/IR/BuiltinDialect.h"  // from @llvm-project
#include "mlir/IR/BuiltinOps.h"  // from @llvm-project
#include "mlir/IR/MLIRContext.h"  // from @llvm-project
#include "mlir/IR/OwningOpRef.h"  // from @llvm-project
#include "mlir/Support/DebugStringHelper.h"  // from @llvm-project
#include "tensorflow/compiler/xla/mlir_hlo/mhlo/IR/hlo_ops.h"
#include "tensorflow/compiler/xla/pjrt/mlir_to_hlo.h"
#include "tensorflow/compiler/xla/python/ifrt/serdes.h"
#include "tensorflow/compiler/xla/python/pjrt_ifrt/xla_compiler.h"

namespace xla {
namespace ifrt {
namespace {

using ::testing::IsNull;
using ::testing::Not;

TEST(XlaProgramSerDesTest, RoundTrip) {
  static constexpr absl::string_view kMlirModuleStr = R"(
module {
  func.func @main(%arg0: tensor<2x3xf32>) -> tensor<2x3xf32> {
    %0 = "mhlo.copy"(%arg0) : (tensor<2x3xf32>) -> tensor<2x3xf32>
    %1 = mhlo.constant dense<1.000000e+00> : tensor<f32>
    %2 = "mhlo.broadcast"(%1) {broadcast_sizes = dense<[2, 3]> : tensor<2xi64>} : (tensor<f32>) -> tensor<2x3xf32>
    %3 = mhlo.add %0, %2 : tensor<2x3xf32>
    return %3 : tensor<2x3xf32>
  }
})";

  mlir::MLIRContext context;

  Serialized serialized;
  {
    TF_ASSERT_OK_AND_ASSIGN(
        mlir::OwningOpRef<mlir::ModuleOp> module,
        xla::ParseMlirModuleString(kMlirModuleStr, context));
    auto program = std::make_unique<XlaProgram>(std::move(module));
    TF_ASSERT_OK_AND_ASSIGN(serialized, Serialize(*program));
  }

  std::unique_ptr<Serializable> deserialized;
  {
    auto deserialize_options =
        std::make_unique<XlaDeserializeProgramOptions>(&context);
    TF_ASSERT_OK_AND_ASSIGN(
        deserialized, Deserialize(serialized, std::move(deserialize_options)));
  }

  auto xla_program = llvm::dyn_cast<XlaProgram>(deserialized.get());
  ASSERT_THAT(xla_program, Not(IsNull()));

  // Verify that the deserialized program has no StableHLO ops.
  bool has_unsupported_dialect = false;
  xla_program->mlir_module->walk([&](mlir::Operation *op) {
    if (!llvm::isa<mlir::BuiltinDialect, mlir::func::FuncDialect,
                   mlir::mhlo::MhloDialect>(op->getDialect())) {
      LOG(ERROR) << "Found an op with an unsupported dialect: "
                 << mlir::debugString(op);
      has_unsupported_dialect = true;
    }
  });
  EXPECT_FALSE(has_unsupported_dialect);
}

}  // namespace
}  // namespace ifrt
}  // namespace xla
