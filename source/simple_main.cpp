/**
 * This file is part of the Fall 2023, CSE 491 course project.
 * @brief A simplistic main file to demonstrate a system.
 * @note Status: PROPOSAL
 **/

// Include the modules that we will be using.
#include "Agents/PathAgent.hpp"
#include "Agents/AStarAgent.hpp"
#include "Interfaces/TrashInterface.hpp"
#include "Worlds/MazeWorld.hpp"

int main() {
  cse491::MazeWorld world;

  // Will print failed to initialize agent 'Looper' due to not being given
  auto & entity = world.AddAgent<walle::PathAgent>("Looper").SetPosition(6,0).SetProperty("symbol", '$');
  assert(dynamic_cast<walle::PathAgent *>(&entity));
  auto & looper = static_cast<walle::PathAgent &>(entity);
  looper.SetProperty<std::basic_string_view<char>>("path", "e 4s w 4n");
  looper.Initialize();

  auto agent = dynamic_cast<walle::AStarAgent *>(&world.AddAgent<walle::AStarAgent>("Pacer 1"));
  agent->SetPosition(3, 1);
  agent->SetGoalPosition(3, 6);
  agent->SetWorld(&world);


  world.AddAgent<cse491::TrashInterface>("Interface").SetProperty("symbol", '@');

  world.Run();
}