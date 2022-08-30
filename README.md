# -- FdF (Fil de Fer) --

## Usage (mac only) -- 👈

```bash
git clone https://github.com/NetworkFlux/push_swap.git && cd FdF && bash launch.sh
```

<img src="fill img" width="400" height="250"> <img src="fill img" width="400" height="250">

## Topics -- 🗝

1. 3D Graphics Programming

2. Graphic Library

3. Events

4. C

  

## Challenge -- 💡

  

Creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments.

  
  

## Objectives -- ✅

  

The wireframe should be able

- **700** instructions on average for a stack of **100** integers

- **5000** instructions on average for a stack of **500** integers


## Rules -- 🚨

If you are interested in the specifics of the project here is how it is supposed to work :

-	You have 2 stacks named a and b.

-	At the beginning :

	The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.

	The stack b is empty.

-	The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal :

	sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

	sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

	ss : sa and sb at the same time.

	pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

	pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

	ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

	rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

	rr : ra and rb at the same time.

	rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

	rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

	rrr : rra and rrb at the same time.



👍 Thanks to [o-reo](https://github.com/o-reo "o-reo GitHub") for his [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer "push_swap visualizer") ! 👍