/**
 * This file is part of the Fall 2023, CSE 491 Course Project
 * @brief An Agent that will move around using random actions
 * @note Status: PROPOSAL
 * @author Yousif Murrani
 **/

#pragma once

#include <cassert>
#include "../core/AgentBase.hpp"
#include "../core/GridPosition.hpp"
#include "../core/WorldBase.hpp"

namespace walle {

    /**
     * @class RandomAgent
     * @brief Class for the Random Agent
     */
    class RandomAgent : public cse491::AgentBase {

        private:

            double mRandom = 0.0;   /// Random factor

            bool mMoving = true;    /// Is the agent moving

        public:
            /// @brief  Constructor
            /// @param id ID of the agent
            /// @param name name of the agent
            RandomAgent(size_t id, const std::string &name) : AgentBase(id, name) {}

            ~RandomAgent() = default;

            /// @brief This agent needs a specific set of actions to function.
            /// @return Success.
            bool Initialize() override {
                return HasAction("up") && HasAction("down") && HasAction("left") && HasAction("right");
            }

            /// @brief Choose the action to take a step in the random direction
            size_t SelectAction(const cse491::WorldGrid & /*grid*/,
                                const cse491::type_options_t & /* type_options*/,
                                const cse491::item_map_t & /* item_map*/,
                                const cse491::agent_map_t & /* agent_map*/) override {
                // We are taking an action so another turn has passed

                CalculateRandom(4);

                if(mMoving){
                    if(mRandom < 1.0){
                        return action_map["up"];
                    }
                    else if(mRandom < 2.0){
                        return action_map["down"];
                    }
                    else if(mRandom < 3.0){
                        return action_map["left"];
                    }
                    else{
                        return action_map["right"];
                    }
                }

                return 0; // should not reach this point
            }
           
            /// @brief Function to calculate the random direction
            /// @param multiplier random multiplier
            void CalculateRandom(double multiplier){
                mRandom = GetWorld().GetRandom(multiplier);
            }

            /// @brief Function to set the double for the random variable
            /// @param direction direction to set
            void SetDirection(double direction) { mRandom = direction; }

            /// @brief Function to set the bool for the move variable
            /// @param move move to set
            void SetMoving(bool move) { mMoving = move; }

    };

} // namespace walle