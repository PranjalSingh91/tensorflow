load("//tensorflow/core/platform:rules_cc.bzl", "cc_library")
load("//tensorflow:tensorflow.bzl", "if_oss", "tf_cc_test")
load("//tensorflow/core/profiler/builds:build_config.bzl", "tf_profiler_copts")

package(
    # copybara:uncomment default_applicable_licenses = ["//tensorflow:license"],
    default_visibility = ["//tensorflow/core/profiler:internal"],
    licenses = ["notice"],
)

cc_library(
    name = "xplane_to_op_metrics_db",
    srcs = ["xplane_to_op_metrics_db.cc"],
    hdrs = ["xplane_to_op_metrics_db.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_metrics_db_combiner",
        ":op_stack",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:cost_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "//tensorflow/core/profiler/utils:op_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:timespan",
        "//tensorflow/core/profiler/utils:trace_utils",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/utils:tf_op_utils",
        "@com_google_absl//absl/algorithm:container",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:optional",
    ],
)

tf_cc_test(
    name = "xplane_to_op_metrics_db_test",
    size = "small",
    srcs = ["xplane_to_op_metrics_db_test.cc"],
    deps = [
        ":xplane_to_op_metrics_db",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_metrics_db_combiner",
    srcs = ["op_metrics_db_combiner.cc"],
    hdrs = ["op_metrics_db_combiner.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core/platform:protobuf",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "@com_google_absl//absl/container:flat_hash_map",
    ],
)

cc_library(
    name = "op_metrics_to_record",
    srcs = ["op_metrics_to_record.cc"],
    hdrs = ["op_metrics_to_record.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/utils:math_utils",
        "@com_google_absl//absl/algorithm:container",
    ],
)

cc_library(
    name = "op_stack",
    hdrs = ["op_stack.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
    ],
)

cc_library(
    name = "op_stats_to_op_profile",
    srcs = ["op_stats_to_op_profile.cc"],
    hdrs = ["op_stats_to_op_profile.h"],
    deps = [
        ":op_profile_builder",
        "//tensorflow/core/platform:logging",
        "//tensorflow/core/profiler/protobuf:hardware_types_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_profile_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_stats_to_overview_page",
    srcs = ["op_stats_to_overview_page.cc"],
    hdrs = ["op_stats_to_overview_page.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_metrics_to_record",
        ":op_stats_to_input_pipeline_analysis",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:hardware_types_proto_cc",
        "//tensorflow/core/profiler/protobuf:input_pipeline_proto_cc",
        "//tensorflow/core/profiler/protobuf:kernel_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:overview_page_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_function_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:diagnostics",
        "//tensorflow/core/profiler/utils:hardware_type_utils",
        "//tensorflow/core/profiler/utils:html_utils",
        "//tensorflow/core/profiler/utils:kernel_stats_utils",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/tsl/profiler/utils:format_utils",
        "//tensorflow/tsl/profiler/utils:tf_op_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_stats_to_pod_stats",
    srcs = ["op_stats_to_pod_stats.cc"],
    hdrs = ["op_stats_to_pod_stats.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:pod_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/utils:diagnostics",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:math_utils",
        "@com_google_absl//absl/strings",
    ],
)

tf_cc_test(
    name = "op_stats_to_pod_stats_test",
    srcs = ["op_stats_to_pod_stats_test.cc"],
    deps = [
        ":op_stats_to_pod_stats",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:diagnostics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/utils:diagnostics",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:math_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_stats_to_pod_viewer",
    srcs = ["op_stats_to_pod_viewer.cc"],
    hdrs = ["op_stats_to_pod_viewer.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_stats_to_pod_stats",
        "//tensorflow/core:lib",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:pod_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:pod_viewer_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/utils:diagnostics",
    ],
)

tf_cc_test(
    name = "op_stats_to_pod_viewer_test",
    srcs = ["op_stats_to_pod_viewer_test.cc"],
    deps = [
        ":op_stats_to_pod_viewer",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:diagnostics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:pod_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/utils:diagnostics",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:math_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_stats_to_input_pipeline_analysis",
    srcs = ["op_stats_to_input_pipeline_analysis.cc"],
    hdrs = ["op_stats_to_input_pipeline_analysis.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_metrics_to_record",
        ":step_events_to_steps_db",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/platform:logging",
        "//tensorflow/core/profiler/protobuf:hardware_types_proto_cc",
        "//tensorflow/core/profiler/protobuf:input_pipeline_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/utils:diagnostics",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:hardware_type_utils",
        "//tensorflow/core/profiler/utils:html_utils",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "//tensorflow/tsl/profiler/utils:format_utils",
        "//tensorflow/tsl/profiler/utils:tf_op_utils",
        "//tensorflow/tsl/util:stats_calculator_portable",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_stats_to_tf_stats",
    srcs = ["op_stats_to_tf_stats.cc"],
    hdrs = ["op_stats_to_tf_stats.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_metrics_to_record",
        "//tensorflow/core:lib",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_stats_proto_cc",
        "//tensorflow/core/profiler/utils:kernel_stats_utils",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
    ],
)

tf_cc_test(
    name = "op_stats_to_tf_stats_test",
    size = "small",
    srcs = ["op_stats_to_tf_stats_test.cc"],
    deps = [
        ":op_stats_to_tf_stats",
        ":xplane_to_op_stats",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "step_events_to_steps_db",
    srcs = ["step_events_to_steps_db.cc"],
    hdrs = ["step_events_to_steps_db.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:timespan",
        "@com_google_absl//absl/algorithm:container",
        "@com_google_absl//absl/container:flat_hash_map",
    ],
)

cc_library(
    name = "xplane_to_op_stats",
    srcs = ["xplane_to_op_stats.cc"],
    hdrs = ["xplane_to_op_stats.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_metrics_db_combiner",
        ":repository",
        ":step_events_to_steps_db",
        ":xplane_to_kernel_stats_db",
        ":xplane_to_op_metrics_db",
        ":xplane_to_step_events",
        "//tensorflow/core/profiler/protobuf:diagnostics_proto_cc",
        "//tensorflow/core/profiler/protobuf:hardware_types_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_function_proto_cc",
        "//tensorflow/core/profiler/utils:device_caps_utils",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:hardware_type_utils",
        "//tensorflow/core/profiler/utils:kernel_stats_utils",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:tpu_xplane_utils",
        "//tensorflow/tsl/profiler/utils:xplane_schema",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "multi_xplanes_to_op_stats",
    srcs = ["multi_xplanes_to_op_stats.cc"],
    hdrs = ["multi_xplanes_to_op_stats.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_stats_combiner",
        ":preprocess_single_host_xplane",
        ":repository",
        ":xplane_to_op_stats",
        "//tensorflow/core/platform:status",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:hardware_type_utils",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
    ],
)

tf_cc_test(
    name = "xplane_to_op_stats_test",
    size = "small",
    srcs = ["xplane_to_op_stats_test.cc"],
    deps = [
        ":multi_xplanes_to_op_stats",
        ":repository",
        ":step_events_to_steps_db",
        ":xplane_to_op_stats",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:diagnostics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_function_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:group_events",
    ],
)

cc_library(
    name = "xplane_to_step_events",
    srcs = ["xplane_to_step_events.cc"],
    hdrs = ["xplane_to_step_events.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:timespan",
        "//tensorflow/core/profiler/utils:trace_utils",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/utils:tf_op_utils",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:optional",
    ],
)

tf_cc_test(
    name = "xplane_to_step_events_test",
    size = "small",
    srcs = ["xplane_to_step_events_test.cc"],
    deps = [
        ":xplane_to_step_events",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:event_span",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "//tensorflow/tsl/profiler/utils:group_events",
        "@com_google_absl//absl/container:flat_hash_map",
    ],
)

cc_library(
    name = "xplane_to_kernel_stats_db",
    srcs = ["xplane_to_kernel_stats_db.cc"],
    hdrs = ["xplane_to_kernel_stats_db.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:kernel_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:gpu_event_stats",
        "//tensorflow/core/profiler/utils:kernel_stats_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:trace_utils",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/utils:tf_op_utils",
        "@com_google_absl//absl/strings",
    ],
)

tf_cc_test(
    name = "xplane_to_kernel_stats_db_test",
    size = "small",
    srcs = ["xplane_to_kernel_stats_db_test.cc"],
    deps = [
        ":xplane_to_kernel_stats_db",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:kernel_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:kernel_stats_utils",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "xplane_to_tf_functions",
    srcs = ["xplane_to_tf_functions.cc"],
    hdrs = ["xplane_to_tf_functions.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:tf_function_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:timespan",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "@com_google_absl//absl/algorithm:container",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:optional",
    ],
)

tf_cc_test(
    name = "xplane_to_tf_functions_test",
    size = "small",
    srcs = ["xplane_to_tf_functions_test.cc"],
    deps = [
        ":xplane_to_tf_functions",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:tf_function_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "xplane_to_memory_profile",
    srcs = ["xplane_to_memory_profile.cc"],
    hdrs = ["xplane_to_memory_profile.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:framework",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/framework:protos_all_cc",
        "//tensorflow/core/platform:protobuf",
        "//tensorflow/core/profiler/protobuf:memory_profile_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "@com_google_absl//absl/algorithm:container",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:optional",
    ],
)

tf_cc_test(
    name = "xplane_to_memory_profile_test",
    size = "small",
    srcs = ["xplane_to_memory_profile_test.cc"],
    deps = [
        ":xplane_to_memory_profile",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:memory_profile_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
        "//tensorflow/tsl/profiler/utils:group_events",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_stats_combiner",
    srcs = ["op_stats_combiner.cc"],
    hdrs = ["op_stats_combiner.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":op_metrics_db_combiner",
        ":xplane_to_tf_functions",
        "//tensorflow/core:lib",
        "//tensorflow/core/profiler/protobuf:diagnostics_proto_cc",
        "//tensorflow/core/profiler/protobuf:hardware_types_proto_cc",
        "//tensorflow/core/profiler/protobuf:kernel_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:steps_db_proto_cc",
        "//tensorflow/core/profiler/protobuf:topology_proto_cc",
        "//tensorflow/core/profiler/utils:hardware_type_utils",
        "//tensorflow/core/profiler/utils:kernel_stats_utils",
        "//tensorflow/core/profiler/utils:step_intersection",
        "@com_google_absl//absl/container:flat_hash_map",
    ],
)

cc_library(
    name = "preprocess_single_host_xplane",
    srcs = ["preprocess_single_host_xplane.cc"],
    hdrs = ["preprocess_single_host_xplane.h"],
    copts = tf_profiler_copts(),
    visibility = ["//tensorflow/core/profiler:internal"],
    deps = [
        "//tensorflow/core/profiler/utils:derived_timeline",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:group_events",
        "//tensorflow/tsl/profiler/utils:preprocess_xplane",
        "//tensorflow/tsl/profiler/utils:xplane_utils",
    ],
)

cc_library(
    name = "xplane_to_tools_data",
    srcs = ["xplane_to_tools_data.cc"],
    hdrs = ["xplane_to_tools_data.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":hlo_to_tools_data",
        ":multi_xplanes_to_op_stats",
        ":op_stats_to_input_pipeline_analysis",
        ":op_stats_to_op_profile",
        ":op_stats_to_overview_page",
        ":op_stats_to_pod_viewer",
        ":op_stats_to_tf_stats",
        ":preprocess_single_host_xplane",
        ":process_megascale_dcn",
        ":repository",
        ":tool_options",
        ":xplane_to_memory_profile",
        ":xplane_to_op_stats",
        ":xplane_to_tf_data_stats",
        ":xplane_to_tf_functions",
        ":xplane_to_tool_names",
        ":xplane_to_trace_container",
        "//tensorflow/core:lib",
        "//tensorflow/core/profiler/convert/trace_viewer:trace_events_to_json",
        "//tensorflow/core/profiler/protobuf:hardware_types_proto_cc",
        "//tensorflow/core/profiler/protobuf:input_pipeline_proto_cc",
        "//tensorflow/core/profiler/protobuf:kernel_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_profile_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:overview_page_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_data_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:tf_stats_proto_cc",
        "//tensorflow/core/profiler/utils:hardware_type_utils",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/tsl/profiler/convert:xplane_to_trace_events",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "xplane_to_tf_data_stats",
    srcs = ["xplane_to_tf_data_stats.cc"],
    hdrs = ["xplane_to_tf_data_stats.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:tf_data_stats_proto_cc",
        "//tensorflow/core/profiler/utils:html_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:timespan",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:group_events",
        "//tensorflow/tsl/profiler/utils:tf_op_utils",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:str_format",
    ],
)

tf_cc_test(
    name = "xplane_to_tf_data_stats_test",
    size = "small",
    srcs = ["xplane_to_tf_data_stats_test.cc"],
    tags = if_oss([
        "manual",
        "no_oss",
    ]),  # b/169705709, no protobuf matchers in OSS.
    deps = [
        ":xplane_to_tf_data_stats",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:tf_data_stats_proto_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_test_utils",
    ],
)

cc_library(
    name = "xplane_to_step_stats",
    srcs = ["xplane_to_step_stats.cc"],
    hdrs = ["xplane_to_step_stats.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core:protos_all_cc",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/core/profiler/utils:gpu_event_stats",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "hlo_to_tools_data",
    srcs = ["hlo_to_tools_data.cc"],
    hdrs = ["hlo_to_tools_data.h"],
    copts = tf_profiler_copts(),
    visibility = ["//tensorflow:__pkg__"],
    deps = [
        ":hlo_proto_to_graph_view",
        ":hlo_proto_to_memory_visualization_utils",
        ":repository",
        ":tool_options",
        ":xplane_to_hlo",
        "//tensorflow/compiler/xla/service:hlo_proto_cc",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "hlo_proto_to_memory_visualization_utils",
    srcs = ["hlo_proto_to_memory_visualization_utils.cc"],
    hdrs = ["hlo_proto_to_memory_visualization_utils.h"],
    copts = tf_profiler_copts(),
    visibility = ["//tensorflow/core/profiler/protobuf:memory_viewer_friends"],
    deps = [
        "//tensorflow/compiler/xla:shape_util",
        "//tensorflow/compiler/xla:xla_data_proto_cc",
        "//tensorflow/compiler/xla/service:hlo_proto_cc",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core/profiler/protobuf:memory_viewer_preprocess_proto_cc",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:str_format",
        "@com_google_absl//absl/types:span",
    ],
)

tf_cc_test(
    name = "hlo_proto_to_memory_visualization_utils_test",
    srcs = ["hlo_proto_to_memory_visualization_utils_test.cc"],
    deps = [
        ":hlo_proto_to_memory_visualization_utils",
        "//tensorflow/compiler/xla/service:hlo_proto_cc",
        "//tensorflow/core:lib_internal",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/protobuf:memory_viewer_preprocess_proto_cc",
        "//tensorflow/core/util/proto:proto_utils",
        "@com_google_absl//absl/strings:str_format",
        "@com_google_googletest//:gtest",
    ],
)

cc_library(
    name = "xplane_to_hlo",
    srcs = ["xplane_to_hlo.cc"],
    hdrs = ["xplane_to_hlo.h"],
    copts = tf_profiler_copts(),
    deps = [
        ":repository",
        "//tensorflow/compiler/xla/service:hlo_proto_cc",
        "//tensorflow/core:lib",
        "//tensorflow/core/platform:errors",
        "//tensorflow/core/platform:status",
        "//tensorflow/core/platform:statusor",
        "//tensorflow/core/profiler/utils:hlo_proto_map",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:file_system_utils",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "op_profile_builder",
    srcs = ["op_profile_builder.cc"],
    hdrs = ["op_profile_builder.h"],
    deps = [
        ":op_metrics_db_combiner",
        ":op_metrics_to_record",
        "//tensorflow/core:lib",
        "//tensorflow/core:lib_headers_for_pybind",
        "//tensorflow/core/profiler/protobuf:op_metrics_proto_cc",
        "//tensorflow/core/profiler/protobuf:op_profile_proto_cc",
        "//tensorflow/core/profiler/utils:math_utils",
        "//tensorflow/core/profiler/utils:op_metrics_db_utils",
        "//tensorflow/tsl/profiler/convert:xla_op_utils",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:node_hash_map",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "hlo_proto_to_graph_view",
    srcs = ["hlo_proto_to_graph_view.cc"],
    hdrs = ["hlo_proto_to_graph_view.h"],
    deps = [
        ":tool_options",
        "//tensorflow/compiler/xla/hlo/ir:hlo",
        "//tensorflow/compiler/xla/service:hlo_graph_dumper",
        "//tensorflow/compiler/xla/service:hlo_proto_cc",
        "//tensorflow/core/platform:errors",
        "//tensorflow/core/platform:statusor",
        "//tensorflow/core/profiler/utils:hlo_module_utils",
        "//tensorflow/core/profiler/utils:hlo_proto_to_module",
    ],
)

tf_cc_test(
    name = "hlo_proto_to_graph_view_test",
    size = "small",
    srcs = ["hlo_proto_to_graph_view_test.cc"],
    deps = [
        ":hlo_proto_to_graph_view",
        ":tool_options",
        "//tensorflow/compiler/xla/service:hlo_graph_dumper",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/platform:status_matchers",
        "//tensorflow/core/protobuf:error_codes_proto_impl_cc",
    ],
)

cc_library(
    name = "tool_options",
    hdrs = ["tool_options.h"],
    deps = [
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings:str_format",
    ],
)

cc_library(
    name = "repository",
    srcs = ["repository.cc"],
    hdrs = ["repository.h"],
    deps = [
        "//tensorflow/core:lib",
        "//tensorflow/core/platform:errors",
        "//tensorflow/core/platform:statusor",
        "//tensorflow/core/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings",
    ],
)

tf_cc_test(
    name = "repository_test",
    size = "small",
    srcs = ["repository_test.cc"],
    deps = [
        ":repository",
        "//tensorflow/core/platform:errors",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "xplane_to_tool_names",
    srcs = ["xplane_to_tool_names.cc"],
    hdrs = ["xplane_to_tool_names.h"],
    deps = [
        ":repository",
        ":xplane_to_hlo",
        "//tensorflow/core/platform:statusor",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "@com_google_absl//absl/strings",
    ],
)

tf_cc_test(
    name = "xplane_to_tool_names_test",
    size = "small",
    srcs = ["xplane_to_tool_names_test.cc"],
    deps = [
        ":repository",
        ":xplane_to_tool_names",
        "//tensorflow/core:lib",
        "//tensorflow/core:test",
        "//tensorflow/core:test_main",
        "//tensorflow/core/profiler/utils:xplane_schema",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "@com_google_absl//absl/strings",
        "@com_google_googletest//:gtest",
    ],
)

cc_library(
    name = "xplane_to_trace_container",
    srcs = ["xplane_to_trace_container.cc"],
    hdrs = ["xplane_to_trace_container.h"],
    copts = tf_profiler_copts(),
    deps = [
        "//tensorflow/core/profiler/convert/trace_viewer:trace_event_arguments_builder",
        "//tensorflow/core/profiler/convert/trace_viewer:trace_events",
        "//tensorflow/core/profiler/convert/trace_viewer:trace_events_util",
        "//tensorflow/core/profiler/protobuf:trace_events_proto_cc",
        "//tensorflow/core/profiler/protobuf:trace_events_raw_proto_cc",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:timespan",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:xplane_schema",
        "//tensorflow/tsl/profiler/utils:xplane_visitor",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "dcn_utils",
    srcs = ["dcn_utils.cc"],
    hdrs = ["dcn_utils.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//tensorflow/tsl/profiler/utils:xplane_schema",
        "//tensorflow/tsl/profiler/utils:xplane_visitor",
        "@com_google_absl//absl/strings",
    ],
)

tf_cc_test(
    name = "dcn_utils_test",
    srcs = ["dcn_utils_test.cc"],
    deps = [
        ":dcn_utils",
        "//tensorflow/tsl/profiler/utils:tf_xplane_visitor",
        "//tensorflow/tsl/profiler/utils:xplane_builder",
        "//tensorflow/tsl/profiler/utils:xplane_schema",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "dcn_analysis",
    srcs = ["dcn_analysis.cc"],
    hdrs = ["dcn_analysis.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":dcn_utils",
        "//tensorflow/core/profiler/utils:xplane_builder",
        "//tensorflow/core/profiler/utils:xplane_visitor",
        "//tensorflow/tsl/profiler/utils:math_utils",
        "//tensorflow/tsl/profiler/utils:xplane_schema",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "process_megascale_dcn",
    srcs = ["process_megascale_dcn.cc"],
    hdrs = ["process_megascale_dcn.h"],
    deps = [
        ":dcn_analysis",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/core/profiler/utils:xplane_utils",
        "//tensorflow/tsl/profiler/protobuf:xplane_proto_cc",
        "//tensorflow/tsl/profiler/utils:tpu_xplane_utils",
    ],
)

tf_cc_test(
    name = "dcn_analysis_test",
    srcs = ["dcn_analysis_test.cc"],
    deps = [
        ":dcn_analysis",
        ":dcn_utils",
        "//tensorflow/core/profiler/utils:tf_xplane_visitor",
        "//tensorflow/tsl/profiler/utils:xplane_schema",
        "@com_google_googletest//:gtest_main",
    ],
)
