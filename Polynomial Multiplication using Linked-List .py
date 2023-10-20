# Node class for creating linked list nodes
class Node:
    def __init__(self, coeff, power):
        self.coefficient = coeff
        self.power = power
        self.next = None

# Function to multiply two polynomials represented as linked lists
def multiply_poly(poly1, poly2):
    result = None
    temp = poly2

    while temp:
        result = add_poly(result, multiply_term(poly1, temp.coefficient, temp.power))
        temp = temp.next

    return result

# Function to multiply a term of a polynomial with a constant and power
def multiply_term(poly, coeff, power):
    result = None
    temp = poly

    while temp:
        result = add_node(result, Node(temp.coefficient * coeff, temp.power + power))
        temp = temp.next

    return result

# Function to add two nodes to the resulting linked list
def add_node(result, new_node):
    if not result:
        return new_node

    temp = result
    while temp.next:
        temp = temp.next

    temp.next = new_node
    return result

# Function to add two polynomials represented as linked lists
def add_poly(poly1, poly2):
    result = None
    current = None

    while poly1 and poly2:
        if poly1.power == poly2.power:
            temp = Node(poly1.coefficient + poly2.coefficient, poly1.power)
            poly1 = poly1.next
            poly2 = poly2.next
        elif poly1.power > poly2.power:
            temp = Node(poly1.coefficient, poly1.power)
            poly1 = poly1.next
        else:
            temp = Node(poly2.coefficient, poly2.power)
            poly2 = poly2.next

        if not result:
            result = temp
            current = temp
        else:
            current.next = temp
            current = current.next

    while poly1:
        current.next = Node(poly1.coefficient, poly1.power)
        poly1 = poly1.next
        current = current.next

    while poly2:
        current.next = Node(poly2.coefficient, poly2.power)
        poly2 = poly2.next
        current = current.next

    return result

# Example usage
# 2x^2 + 4x + 1
poly1 = Node(2, 2)
poly1.next = Node(4, 1)
poly1.next.next = Node(1, 0)

# 3x + 1
poly2 = Node(3, 1)
poly2.next = Node(1, 0)

result = multiply_poly(poly1, poly2)

# Display the result
temp = result
while temp:
    print(f"{temp.coefficient}x^{temp.power}", end=" ")
    if temp.next and temp.next.coefficient >= 0:
        print("+", end=" ")
    temp = temp.next
