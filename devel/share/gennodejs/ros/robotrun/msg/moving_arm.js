// Auto-generated. Do not edit!

// (in-package robotrun.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class moving_arm {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.hArmBagNum = null;
      this.movingArmBagNum = null;
      this.hIOLine_1 = null;
      this.hIOLine_2 = null;
      this.vIOLine = null;
      this.hArmOnLineLock = null;
      this.hArmOnLineUnlock = null;
      this.hRotateAngle = null;
      this.speed = null;
      this.hTorsion = null;
      this.vRorateAngle = null;
      this.opArmDistance = null;
      this.stayWiresDis = null;
    }
    else {
      if (initObj.hasOwnProperty('hArmBagNum')) {
        this.hArmBagNum = initObj.hArmBagNum
      }
      else {
        this.hArmBagNum = 0;
      }
      if (initObj.hasOwnProperty('movingArmBagNum')) {
        this.movingArmBagNum = initObj.movingArmBagNum
      }
      else {
        this.movingArmBagNum = 0;
      }
      if (initObj.hasOwnProperty('hIOLine_1')) {
        this.hIOLine_1 = initObj.hIOLine_1
      }
      else {
        this.hIOLine_1 = 0;
      }
      if (initObj.hasOwnProperty('hIOLine_2')) {
        this.hIOLine_2 = initObj.hIOLine_2
      }
      else {
        this.hIOLine_2 = 0;
      }
      if (initObj.hasOwnProperty('vIOLine')) {
        this.vIOLine = initObj.vIOLine
      }
      else {
        this.vIOLine = 0;
      }
      if (initObj.hasOwnProperty('hArmOnLineLock')) {
        this.hArmOnLineLock = initObj.hArmOnLineLock
      }
      else {
        this.hArmOnLineLock = 0;
      }
      if (initObj.hasOwnProperty('hArmOnLineUnlock')) {
        this.hArmOnLineUnlock = initObj.hArmOnLineUnlock
      }
      else {
        this.hArmOnLineUnlock = 0;
      }
      if (initObj.hasOwnProperty('hRotateAngle')) {
        this.hRotateAngle = initObj.hRotateAngle
      }
      else {
        this.hRotateAngle = 0;
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = 0;
      }
      if (initObj.hasOwnProperty('hTorsion')) {
        this.hTorsion = initObj.hTorsion
      }
      else {
        this.hTorsion = 0;
      }
      if (initObj.hasOwnProperty('vRorateAngle')) {
        this.vRorateAngle = initObj.vRorateAngle
      }
      else {
        this.vRorateAngle = 0;
      }
      if (initObj.hasOwnProperty('opArmDistance')) {
        this.opArmDistance = initObj.opArmDistance
      }
      else {
        this.opArmDistance = 0;
      }
      if (initObj.hasOwnProperty('stayWiresDis')) {
        this.stayWiresDis = initObj.stayWiresDis
      }
      else {
        this.stayWiresDis = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type moving_arm
    // Serialize message field [hArmBagNum]
    bufferOffset = _serializer.int64(obj.hArmBagNum, buffer, bufferOffset);
    // Serialize message field [movingArmBagNum]
    bufferOffset = _serializer.int64(obj.movingArmBagNum, buffer, bufferOffset);
    // Serialize message field [hIOLine_1]
    bufferOffset = _serializer.int64(obj.hIOLine_1, buffer, bufferOffset);
    // Serialize message field [hIOLine_2]
    bufferOffset = _serializer.int64(obj.hIOLine_2, buffer, bufferOffset);
    // Serialize message field [vIOLine]
    bufferOffset = _serializer.int64(obj.vIOLine, buffer, bufferOffset);
    // Serialize message field [hArmOnLineLock]
    bufferOffset = _serializer.int64(obj.hArmOnLineLock, buffer, bufferOffset);
    // Serialize message field [hArmOnLineUnlock]
    bufferOffset = _serializer.int64(obj.hArmOnLineUnlock, buffer, bufferOffset);
    // Serialize message field [hRotateAngle]
    bufferOffset = _serializer.int64(obj.hRotateAngle, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = _serializer.int64(obj.speed, buffer, bufferOffset);
    // Serialize message field [hTorsion]
    bufferOffset = _serializer.int64(obj.hTorsion, buffer, bufferOffset);
    // Serialize message field [vRorateAngle]
    bufferOffset = _serializer.int64(obj.vRorateAngle, buffer, bufferOffset);
    // Serialize message field [opArmDistance]
    bufferOffset = _serializer.int64(obj.opArmDistance, buffer, bufferOffset);
    // Serialize message field [stayWiresDis]
    bufferOffset = _serializer.int64(obj.stayWiresDis, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type moving_arm
    let len;
    let data = new moving_arm(null);
    // Deserialize message field [hArmBagNum]
    data.hArmBagNum = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [movingArmBagNum]
    data.movingArmBagNum = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hIOLine_1]
    data.hIOLine_1 = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hIOLine_2]
    data.hIOLine_2 = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [vIOLine]
    data.vIOLine = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hArmOnLineLock]
    data.hArmOnLineLock = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hArmOnLineUnlock]
    data.hArmOnLineUnlock = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hRotateAngle]
    data.hRotateAngle = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [hTorsion]
    data.hTorsion = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [vRorateAngle]
    data.vRorateAngle = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [opArmDistance]
    data.opArmDistance = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [stayWiresDis]
    data.stayWiresDis = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 104;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robotrun/moving_arm';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9b792f6978c8450748856eee9a6a014b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new moving_arm(null);
    if (msg.hArmBagNum !== undefined) {
      resolved.hArmBagNum = msg.hArmBagNum;
    }
    else {
      resolved.hArmBagNum = 0
    }

    if (msg.movingArmBagNum !== undefined) {
      resolved.movingArmBagNum = msg.movingArmBagNum;
    }
    else {
      resolved.movingArmBagNum = 0
    }

    if (msg.hIOLine_1 !== undefined) {
      resolved.hIOLine_1 = msg.hIOLine_1;
    }
    else {
      resolved.hIOLine_1 = 0
    }

    if (msg.hIOLine_2 !== undefined) {
      resolved.hIOLine_2 = msg.hIOLine_2;
    }
    else {
      resolved.hIOLine_2 = 0
    }

    if (msg.vIOLine !== undefined) {
      resolved.vIOLine = msg.vIOLine;
    }
    else {
      resolved.vIOLine = 0
    }

    if (msg.hArmOnLineLock !== undefined) {
      resolved.hArmOnLineLock = msg.hArmOnLineLock;
    }
    else {
      resolved.hArmOnLineLock = 0
    }

    if (msg.hArmOnLineUnlock !== undefined) {
      resolved.hArmOnLineUnlock = msg.hArmOnLineUnlock;
    }
    else {
      resolved.hArmOnLineUnlock = 0
    }

    if (msg.hRotateAngle !== undefined) {
      resolved.hRotateAngle = msg.hRotateAngle;
    }
    else {
      resolved.hRotateAngle = 0
    }

    if (msg.speed !== undefined) {
      resolved.speed = msg.speed;
    }
    else {
      resolved.speed = 0
    }

    if (msg.hTorsion !== undefined) {
      resolved.hTorsion = msg.hTorsion;
    }
    else {
      resolved.hTorsion = 0
    }

    if (msg.vRorateAngle !== undefined) {
      resolved.vRorateAngle = msg.vRorateAngle;
    }
    else {
      resolved.vRorateAngle = 0
    }

    if (msg.opArmDistance !== undefined) {
      resolved.opArmDistance = msg.opArmDistance;
    }
    else {
      resolved.opArmDistance = 0
    }

    if (msg.stayWiresDis !== undefined) {
      resolved.stayWiresDis = msg.stayWiresDis;
    }
    else {
      resolved.stayWiresDis = 0
    }

    return resolved;
    }
};

module.exports = moving_arm;
