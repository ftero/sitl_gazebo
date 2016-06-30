/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/* Desc: A 4-wheeled vehicle
 * Author: Nate Koenig
 */

#ifndef _GAZEBO_GIMBAL_CONTROLLER_PLUGIN_HH_
#define _GAZEBO_GIMBAL_CONTROLLER_PLUGIN_HH_

#include <string>
#include <vector>

#include <gazebo/common/PID.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/util/system.hh>

namespace gazebo
{
  class GAZEBO_VISIBLE GimbalControllerPlugin : public ModelPlugin
  {
    /// \brief Constructor
    public: GimbalControllerPlugin();

    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);

    public: virtual void Init();

    private: void OnUpdate();

    private: void OnStringMsg(ConstGzStringPtr &_msg);

    private: sdf::ElementPtr sdf;

    private: std::vector<event::ConnectionPtr> connections;

    private: transport::SubscriberPtr sub;

    private: transport::PublisherPtr pub;

    private: physics::ModelPtr model;

    /// \brief yaw camera
    private: physics::JointPtr yawJoint;

    /// \brief roll camera
    private: physics::JointPtr rollJoint;

    /// \brief tilt camera
    private: physics::JointPtr pitchJoint;

    private: std::string status;

    private: double pitchCommand;
    private: double yawCommand;
    private: double rollCommand;

    private: transport::NodePtr node;

    private: common::PID pitchPid;
    private: common::PID rollPid;
    private: common::PID yawPid;
    private: common::Time lastUpdateTime;
  };
}
#endif
