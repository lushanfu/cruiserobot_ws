// Auto-generated. Do not edit!

// (in-package robotrun.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let moving_arm = require('./moving_arm.js');
let fixed_arm = require('./fixed_arm.js');

//-----------------------------------------------------------

class robot_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.movingArmData = null;
      this.fixedArmData = null;
    }
    else {
      if (initObj.hasOwnProperty('movingArmData')) {
        this.movingArmData = initObj.movingArmData
      }
      else {
        this.movingArmData = new moving_arm();
      }
      if (initObj.hasOwnProperty('fixedArmData')) {
        this.fixedArmData = initObj.fixedArmData
      }
      else {
        this.fixedArmData = new fixed_arm();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type robot_data
    // Serialize message field [movingArmData]
    bufferOffset = moving_arm.serialize(obj.movingArmData, buffer, bufferOffset);
    // Serialize message field [fixedArmData]
    bufferOffset = fixed_arm.serialize(obj.fixedArmData, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type robot_data
    let len;
    let data = new robot_data(null);
    // Deserialize message field [movingArmData]
    data.movingArmData = moving_arm.deserialize(buffer, bufferOffset);
    // Deserialize message field [fixedArmData]
    data.fixedArmData = fixed_arm.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 232;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robotrun/robot_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '06f2154602946c9906cdc04acafe2b9f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    moving_arm movingArmData
    fixed_arm  fixedArmData
    ================================================================================
    MSG: robotrun/moving_arm
    int64 hArmBagNum
    int64 movingArmBagNum
    int64 hIOLine_1
    int64 hIOLine_2
    int64 vIOLine
    int64 hArmOnLineLock
    int64 hArmOnLineUnlock
    int64 hRotateAngle
    int64 speed
    int64 hTorsion
    int64 vRorateAngle
    int64 opArmDistance
    int64 stayWiresDis
    
    ================================================================================
    MSG: robotrun/fixed_arm
    int64 hArmBagNum
    int64 movingArmBagNum
    int64 hIOLine_1
    int64 hIOLine_2
    int64 vIOLine
    int64 hArmOnLineLock
    int64 hArmOnLineUnlock
    int64 hRotateAngle
    int64 speed
    int64 hTorsion
    int64 vRorateAngle
    int64 opArmDistance
    int64 controlCabinetBagNum
    int64 controlCabinetStayWireSensorDis
    int64 gps
    int64 batteryCapcity
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new robot_data(null);
    if (msg.movingArmData !== undefined) {
      resolved.movingArmData = moving_arm.Resolve(msg.movingArmData)
    }
    else {
      resolved.movingArmData = new moving_arm()
    }

    if (msg.fixedArmData !== undefined) {
      resolved.fixedArmData = fixed_arm.Resolve(msg.fixedArmData)
    }
    else {
      resolved.fixedArmData = new fixed_arm()
    }

    return resolved;
    }
};

module.exports = robot_data;
