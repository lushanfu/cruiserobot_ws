// Auto-generated. Do not edit!

// (in-package robotrun.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class op_armRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stopThreshold = null;
      this.travelDirection = null;
    }
    else {
      if (initObj.hasOwnProperty('stopThreshold')) {
        this.stopThreshold = initObj.stopThreshold
      }
      else {
        this.stopThreshold = 0;
      }
      if (initObj.hasOwnProperty('travelDirection')) {
        this.travelDirection = initObj.travelDirection
      }
      else {
        this.travelDirection = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type op_armRequest
    // Serialize message field [stopThreshold]
    bufferOffset = _serializer.int32(obj.stopThreshold, buffer, bufferOffset);
    // Serialize message field [travelDirection]
    bufferOffset = _serializer.int32(obj.travelDirection, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type op_armRequest
    let len;
    let data = new op_armRequest(null);
    // Deserialize message field [stopThreshold]
    data.stopThreshold = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [travelDirection]
    data.travelDirection = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'robotrun/op_armRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '33d66904a6cbb0e030f3253e2c1c9fad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 stopThreshold
    int32 travelDirection
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new op_armRequest(null);
    if (msg.stopThreshold !== undefined) {
      resolved.stopThreshold = msg.stopThreshold;
    }
    else {
      resolved.stopThreshold = 0
    }

    if (msg.travelDirection !== undefined) {
      resolved.travelDirection = msg.travelDirection;
    }
    else {
      resolved.travelDirection = 0
    }

    return resolved;
    }
};

class op_armResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.feedmsg = null;
    }
    else {
      if (initObj.hasOwnProperty('feedmsg')) {
        this.feedmsg = initObj.feedmsg
      }
      else {
        this.feedmsg = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type op_armResponse
    // Serialize message field [feedmsg]
    bufferOffset = _serializer.string(obj.feedmsg, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type op_armResponse
    let len;
    let data = new op_armResponse(null);
    // Deserialize message field [feedmsg]
    data.feedmsg = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.feedmsg.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'robotrun/op_armResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6c15f042b3c8741e7bbc6b472300f5ee';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string feedmsg
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new op_armResponse(null);
    if (msg.feedmsg !== undefined) {
      resolved.feedmsg = msg.feedmsg;
    }
    else {
      resolved.feedmsg = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: op_armRequest,
  Response: op_armResponse,
  md5sum() { return '1d3aaf0f5087764162ba59c4846dda0c'; },
  datatype() { return 'robotrun/op_arm'; }
};
