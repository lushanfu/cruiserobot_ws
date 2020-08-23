# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "robotrun: 3 messages, 1 services")

set(MSG_I_FLAGS "-Irobotrun:/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(robotrun_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" NAME_WE)
add_custom_target(_robotrun_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robotrun" "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" "robotrun/moving_arm:robotrun/fixed_arm"
)

get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" NAME_WE)
add_custom_target(_robotrun_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robotrun" "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" ""
)

get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" NAME_WE)
add_custom_target(_robotrun_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robotrun" "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" ""
)

get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" NAME_WE)
add_custom_target(_robotrun_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robotrun" "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg"
  "${MSG_I_FLAGS}"
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg;/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun
)
_generate_msg_cpp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun
)
_generate_msg_cpp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun
)

### Generating Services
_generate_srv_cpp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun
)

### Generating Module File
_generate_module_cpp(robotrun
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(robotrun_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(robotrun_generate_messages robotrun_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_cpp _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_cpp _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_cpp _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" NAME_WE)
add_dependencies(robotrun_generate_messages_cpp _robotrun_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotrun_gencpp)
add_dependencies(robotrun_gencpp robotrun_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotrun_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg"
  "${MSG_I_FLAGS}"
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg;/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun
)
_generate_msg_eus(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun
)
_generate_msg_eus(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun
)

### Generating Services
_generate_srv_eus(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun
)

### Generating Module File
_generate_module_eus(robotrun
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(robotrun_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(robotrun_generate_messages robotrun_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_eus _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_eus _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_eus _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" NAME_WE)
add_dependencies(robotrun_generate_messages_eus _robotrun_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotrun_geneus)
add_dependencies(robotrun_geneus robotrun_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotrun_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg"
  "${MSG_I_FLAGS}"
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg;/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun
)
_generate_msg_lisp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun
)
_generate_msg_lisp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun
)

### Generating Services
_generate_srv_lisp(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun
)

### Generating Module File
_generate_module_lisp(robotrun
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(robotrun_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(robotrun_generate_messages robotrun_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_lisp _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_lisp _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_lisp _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" NAME_WE)
add_dependencies(robotrun_generate_messages_lisp _robotrun_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotrun_genlisp)
add_dependencies(robotrun_genlisp robotrun_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotrun_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg"
  "${MSG_I_FLAGS}"
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg;/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun
)
_generate_msg_nodejs(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun
)
_generate_msg_nodejs(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun
)

### Generating Services
_generate_srv_nodejs(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun
)

### Generating Module File
_generate_module_nodejs(robotrun
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(robotrun_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(robotrun_generate_messages robotrun_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_nodejs _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_nodejs _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_nodejs _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" NAME_WE)
add_dependencies(robotrun_generate_messages_nodejs _robotrun_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotrun_gennodejs)
add_dependencies(robotrun_gennodejs robotrun_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotrun_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg"
  "${MSG_I_FLAGS}"
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg;/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun
)
_generate_msg_py(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun
)
_generate_msg_py(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun
)

### Generating Services
_generate_srv_py(robotrun
  "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun
)

### Generating Module File
_generate_module_py(robotrun
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(robotrun_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(robotrun_generate_messages robotrun_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/robot_data.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_py _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/fixed_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_py _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/msg/moving_arm.msg" NAME_WE)
add_dependencies(robotrun_generate_messages_py _robotrun_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lsf/LSF/cruiserobot_ws/src/robotrun/srv/op_arm.srv" NAME_WE)
add_dependencies(robotrun_generate_messages_py _robotrun_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotrun_genpy)
add_dependencies(robotrun_genpy robotrun_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotrun_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotrun
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(robotrun_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robotrun
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(robotrun_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotrun
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(robotrun_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robotrun
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(robotrun_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotrun
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(robotrun_generate_messages_py std_msgs_generate_messages_py)
endif()
