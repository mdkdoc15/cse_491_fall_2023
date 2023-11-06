# Team Wall-E : Behavioral Function Library for Autonomous Agents

### Members:

- David Rackerby
- Matt Kight
- Monika Kanphade
- Yousif Murrani

## Documentation

#### Code Style

1. Code should be styled according to the [Google C++ Style
   Guide](https://google.github.io/styleguide/cppguide.html)
2. All code should be contained inside of the namespace `walle`
3. If your text editor doesn't have a built-in linter/formatter, use
   `clang-format` with the `--style=google`

## Goals

#### Library Functions

Implement a set of common library functions that interface with the other
modules.

##### Path algorithms

1. `get_shortest_path(start : Point, end : Point, map : grid)`
   i. A* search to get path between start and end point on map  
   ii. Returns : List of instructions to navigate from start to end  
   iii. Exact actions and return values will be dependent on the Agent calling
   the function

2. `get_random_path(start: Point, num_moves : int, map: grid)`
   i. Return a list of actions of len num_moves

3. `walk_route(start: Point, end: Point, pace: double)`
   i. find certain path between two points
   ii. walk between the path between the two points at certain pace

#### Interaction Functions

1. `is_colliding(agent1 : Agent, agent2: Agent)`  
   i. Checks the position of agent1 in relation to agent2   
   ii. Returns true if there is overlap between agent1 and agent2

2. `broadcast_message(agent_sending: Agent, message: string, ... Extra params about message)`
    1. Send message to world for other agents to interpret
3. `converge_tracker()`
    1. Get all similar typed agents to converge on a location or target

4. `set_state(agent1 : Agent)`
    1. Switch between states such as healthy, dead, and taking_damage

#### Challenge

1. Creating an Autonomous agent that is capable of moving around an interacting
   with the world
2. Working with other agent teams to implement functionality they need for their agents
