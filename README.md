# Implement Prim's and Kruskal algorithm. 
Name: Ram Chandra Jangir

Roll Number : CS21M517

Registered Mail ID: contactjangir@gmail.com



# How to compile and run the program:

**Step-1 :**

Clone this project using below command and you will get below list of files.

       git clone https://github.com/contactjangir/min-spanning-tree.git

       cd min-spanning-tree

       min-spanning-tree$ tree
	.
	├── kruskals
	├── kruskals.cpp
	├── Makefile
	├── output_kruskals.txt
	├── output_prims.txt
	├── prims.cpp
	└── README.md

0 directories, 7 files


**Step-2 :**

It is already having a precompiled two binaries prims and kruskals which can be run directly on Ubuntu system.

OR

How to compile

	min-spanning-tree$ make
	g++ -std=c++11 -o prims prims.cpp
	g++ -std=c++11 -o kruskals kruskals.cpp



**Step-3 :**

**How to run this program for Prim's Algorithm**

	min-spanning-tree$ ./prims

Using Prim's algorithm to find a minimum spanning tree for the following Graph:

	  2        3
	(0)-----(1)------(2)
	|       / \      |
	|      /   \     |
	|     /     \    |
	6   8/       \5  |7
	|   /         \  |
	|  /           \ |
	| /             \|
	(3)-------------(4)
         	9


--------------------------------------------------

Following are the edges in the constructed MST:

0 - 1

1 - 2

0 - 3

1 - 4

Minimum Cost of the Spanning Tree: 16






# **Step-4 :**

# **How to run this program for Kruskal's Algorithm**

	min-spanning-tree$ ./kruskals

Using Kruskal's algorithm to find a minimum spanning tree for the following Graph:

		10
 	0----------1
 	| \        |
 	|  \       |
 	|   \      |
	6|    \ 5   |15
 	|     \    |
 	|      \   |
 	|       \  |
 	2----------3
      	4

--------------------------------------------------


Following are the edges in the constructed MST

2 -- 3 == 4

0 -- 3 == 5

0 -- 1 == 10


Minimum Cost Spanning Tree: 19

