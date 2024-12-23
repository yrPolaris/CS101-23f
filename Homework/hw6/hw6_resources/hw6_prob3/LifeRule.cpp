#include <cctype>
#include "LifeRule.h"
#include "GameWorld.h"
#include "GameSettings.h"

int LifeRuleBase::CountAliveNeighbors(const CellNeighbors &neighbors) const
{
    int count_alive = 0;            // Count the number of alive neighbors
    for (auto neighbor : neighbors) // Loop through all neighbors
    {
        if (neighbor->IsAlive()) // If the neighbor is alive
        {
            ++count_alive; // Then increase the count
        }
    }
    return count_alive; // Return the count
}

void LifeRuleBase::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    const int count_alive = CountAliveNeighbors(neighbors); // Count the number of alive neighbors

    // If the current cell is alive and the number of alive neighbors is not in the set of numbers that the cell survives with
    if (current->IsAlive() && (!BASE_CELL_SURVIVE_CONDITION.count(count_alive)))
    {
        current->SetState(CELL_STATE_DEAD);
        return;
    }
    // If the current cell is dead and the number of alive neighbors is in the set of numbers that the cell is born with
    if (!current->IsAlive() && BASE_CELL_BIRTH_CONDITION.count(count_alive))
    {
        current->SetState(CELL_STATE_ALIVE);
        return;
    }
}

CellNeighbors LifeRuleBase::GetNeighbors(const GameWorld *const game_world, const int x, const int y) const
{
    // Get the neighbors of the cell at position x, y
    CellNeighbors neighbors;
    // Loop through all the neighbors
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int next_x = x + i;
            int next_y = y + j;
            // If the position is not exceeding the boundaries of the world
            if (game_world->CheckPosValid(next_x, next_y))
            {
                // Add the neighbor to the list of neighbors
                neighbors.push_back(game_world->GetCell(next_x, next_y));
            }
        }
    }
    // Return the list of neighbors
    return neighbors;
}

void LifeRuleColorised::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    if (!current->IsAlive() && BASE_CELL_BIRTH_CONDITION.count(CountAliveNeighbors(neighbors)))
    {
        int countred = 0;
        int countblue = 0;
        for (const CellPointer &judge : neighbors)
        {
            if (judge->GetState() == CELL_STATE_RED)
            {
                countred++;
            }
            else if(judge->GetState() == CELL_STATE_BLUE)
            {
                countblue++;
            }
        }
        if (countred > countblue)
        {
            current->SetState(CELL_STATE_RED);
        }
        else if (countred < countblue)
        {
            current->SetState(CELL_STATE_BLUE);
        }
        return;
    }
    else if (current->IsAlive() && (!BASE_CELL_SURVIVE_CONDITION.count(CountAliveNeighbors(neighbors))))
    {
        current->SetState(CELL_STATE_DEAD);
        return;
    }
}

CellNeighbors LifeRuleExtended::GetNeighbors(const GameWorld *const game_world, const int x, const int y) const
{
    CellNeighbors neighbors;
    for (int i = -2; i <= 2; ++i)
    {
        for (int j = -2; j <= 2; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int next_x = x + i;
            int next_y = y + j;
            if (game_world->CheckPosValid(next_x, next_y))
            {
                neighbors.push_back(game_world->GetCell(next_x, next_y));
            }
        }
    }
    return neighbors;
}

void LifeRuleWeighted::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    int influence = 0;
    for (const CellPointer &near : neighbors)
    {
        if (near->GetState() == CELL_STATE_ALIVE)
        {
            int x_current = current->GetX();
            int y_current = current->GetY();
            int x_neighbors = near->GetX();
            int y_neighbors = near->GetY();
            if (((int)abs(x_current-x_neighbors)+(int)abs(y_current-y_neighbors)) <= 2)
            {
                influence += 2;
            }
            else if (((int)abs(x_current-x_neighbors)+(int)abs(y_current-y_neighbors)) > 2)
            {
                influence += 1;
            }
        }
    }
    if (influence < 4 || influence >6)
    {
        current->SetState(CELL_STATE_DEAD);
    }
    else if (current->GetState() == CELL_STATE_ALIVE && influence >= 4 && influence <= 6)
    {
        current->SetState(CELL_STATE_ALIVE);
    }
    else if (current->GetState() == CELL_STATE_DEAD && influence >= 5 && influence <= 6)
    {
        current->SetState(CELL_STATE_ALIVE);
    }
    return;
}

CellNeighbors LifeRuleWeighted::GetNeighbors(const GameWorld *const game_world, const int x, const int y) const
{
    CellNeighbors neighbors;
    for (int i = -2; i <= 2; ++i)
    {
        for (int j = -2; j <= 2; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int next_x = x + i;
            int next_y = y + j;
            if (game_world->CheckPosValid(next_x, next_y))
            {
                neighbors.push_back(game_world->GetCell(next_x, next_y));
            }
        }
    }
    return neighbors;
}

void LifeRuleGenerations::DetermineNextState(const CellPointer &current, const CellNeighbors &neighbors)
{
    if (current->GetState() == CELL_STATE_DEAD && BASE_CELL_BIRTH_CONDITION.count(CountAliveNeighbors(neighbors)))
    {
        current->SetState(CELL_STATE_ALIVE);
    }
    else if (current->GetState() == CELL_STATE_ALIVE && !(BASE_CELL_SURVIVE_CONDITION.count(CountAliveNeighbors(neighbors))))
    {
        current->IncreaseState();
    }
    else if (current->GetState() >= 2 && current->GetState() < MAX_GENERATIONS - 1)
    {
        current->IncreaseState(); 
    }
    else if (current->GetState() == MAX_GENERATIONS - 1)
    {
        current->SetState(CELL_STATE_DEAD);
    }
}










