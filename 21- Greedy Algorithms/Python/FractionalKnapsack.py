def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    ratio = [(values[i] / weights[i], weights[i]) for i in range(n)]
    ratio.sort(reverse=True)

    total = 0
    rem_cap = capacity

    for i in range(n):
        if rem_cap >= ratio[i][1]:
            total += values[weights.index(ratio[i][1])]
            rem_cap -= ratio[i][1]
        else:
            total += ratio[i][0] * rem_cap
            break

    return total

weights = [100, 250, 400]
values = [60, 120, 1200]
capacity = 50

result = fractional_knapsack(weights, values, capacity)
print(result)
