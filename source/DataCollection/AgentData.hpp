#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "DoubleLinkedList.hpp"
#include "../core/GridPosition.hpp"

namespace DataCollection
{
    class AgentData
    {
    private:
        std::string name;
        std::vector<std::unordered_map<std::string, size_t>> actions;
        DoubleLinkedList<cse491::GridPosition> position;
        int position_size = 0;
    public:
        AgentData() = default;
//        AgentData(std::string name) : name(name) {}
        virtual ~AgentData() = default;
        void store_positions(cse491::GridPosition pos){
            position.add_node(pos);
            position_size += 1;
        }
        int get_position_size() { return position_size; }
    };
} // namespace DataCollection