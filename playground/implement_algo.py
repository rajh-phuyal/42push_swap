import sys
import random

int_min = -1000
int_max = 1000
sample_size = 100

stack_a = random.choices(range(int_min, int_max + 1), k=sample_size)
stack_b = []

# for use cases
total_moves = 0
sorted_stack = sorted(stack_a)


def get_min_max_odd():
    odd = sorted([x for x in stack_a if x % 2 == 1])
    try:
        min_odd, max_odd = odd[0], odd[len(odd) - 1]
    except IndexError:
        return None

    return (min_odd, max_odd)


def get_min_max_even():
    even = sorted([x for x in stack_a if x % 2 == 0])
    try:
        min_even, max_even = even[0], even[len(even) - 1]
    except IndexError:
        return None

    return (min_even, max_even)


def print_stacks():
    print("STACK A ", stack_a)
    print("STACK B ", stack_b)


def check_stack_sorted(stack):
    return all(stack[i] <= stack[i+1] for i in range(len(stack)-1))


def sa():
    global stack_a, total_moves
    stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
    print("sa")
    total_moves += 1


def sb():
    global stack_b, total_moves
    stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    print("sb")
    total_moves += 1


def pa():
    global stack_a, stack_b, total_moves
    stack_a.insert(0, stack_b[0])
    stack_b.pop(0)
    print("pa")
    total_moves += 1


def pb():
    global stack_a, stack_b, total_moves
    stack_b.insert(0, stack_a[0])
    stack_a.pop(0)
    print("pb")
    total_moves += 1


def ra():
    global stack_a, total_moves
    stack_a = stack_a[1:] + [stack_a[0]]
    print("ra")
    total_moves += 1


def rb():
    global stack_b, total_moves
    stack_b = stack_b[1:] + [stack_b[0]]
    print("rb")
    total_moves += 1


def rra():
    global stack_a, total_moves
    stack_a = [stack_a[-1]] + stack_a[:-1]
    print("rra")
    total_moves += 1


def rrb():
    global stack_b, total_moves
    stack_b = [stack_b[-1]] + stack_b[:-1]
    print("rrb")
    total_moves += 1


def send_up(val):
    global stack_a
    while stack_a[0] != val:
        ra()
    pb()


def send_down(val):
    global stack_a
    while stack_a[0] != val:
        rra()
    pb()


def send_evens(min_even, max_even):
    global stack_a
    min_index = stack_a.index(min_even)
    max_index = stack_a.index(max_even)

    min_cost = min_index if min_index < len(
        stack_a) - min_index else len(stack_a) - min_index
    max_cost = max_index if max_index < len(
        stack_a) - max_index else len(stack_a) - max_index

    if min_cost <= max_cost:
        val = min_even
        use_index = min_index
    else:
        val = min_even
        use_index = min_index
    if stack_a.index(val) < len(stack_a) - use_index:
        send_up(val)
    else:
        send_down(val)


def send_odds(min_odds, max_odds):
    global stack_a
    min_index = stack_a.index(min_odds)
    max_index = stack_a.index(max_odds)

    min_cost = min_index if min_index < len(
        stack_a) - min_index else len(stack_a) - min_index
    max_cost = max_index if max_index < len(
        stack_a) - max_index else len(stack_a) - max_index

    if min_cost <= max_cost:
        val = max_odds
        use_index = max_index
    else:
        val = max_odds
        use_index = max_index
    if stack_a.index(val) < len(stack_a) - use_index:
        send_up(val)
    else:
        send_down(val)
    # rb()


def main():
    global stack_a, stack_b, total_moves
    print_stacks()
    print("STACK A COUNT", len(stack_a))

    min_even, max_even = get_min_max_even()
    min_odd, max_odd = get_min_max_odd()

    even_count = len(list(filter(lambda x: x % 2 == 0, stack_a)))
    odd_count = len(list(filter(lambda x: x % 2 != 0, stack_a)))

    while odd_count != 0:
        try:
            min_odd, max_odd = get_min_max_odd()
        except TypeError:
            break
        send_odds(min_odd, max_odd)
        odd_count -= 1

    while even_count != 0:
        try:
            min_even, max_even = get_min_max_even()
        except TypeError:
            break
        send_evens(min_even, max_even)
        even_count -= 1


    while even_count != 0:
        try:
            min_even, max_even = get_min_max_even()
        except TypeError:
            break
        send_evens(min_even, max_even)
        even_count -= 1

    print("First")
    print_stacks()

    b_len = len(stack_b) - 1
    while (b_len >= 0):
        if stack_b[0] > stack_b[b_len]:
            pa()
        else:
            rrb()
            pa()
        b_len -= 1

    print("Second")
    print_stacks()

    if check_stack_sorted(stack_a):
        print("WTF")
    print("SORTED STACK A : ", sorted(stack_a))

    print("TOTAL MOVES: ", total_moves)


if __name__ == "__main__":
    main()
