//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx; // add the index at end of heap
        upheap(size, weightArr); // restore order using upheap()
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if(size == 0) {
            return -1;
        }
        int smallest = data[0]; // root is the smallest
        data[0] = data[size-1]; // replace root with last element
        size--;
        downheap(0, weightArr);
        return smallest; //return smallest index
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos -1)/2; //set middle element as parent
        while (pos > 0){
            if (weightArr[data[pos]] < weightArr[data[parent]]){
                int temp = data[pos]; // swap pos and parent
                data[pos] = data[parent];
                data[parent] = temp;
                pos = parent;
                parent = (pos -1)/2;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while(true){
            int leftC = 2 * pos + 1; // if 4->6 <-8, data: [6, 4, 8]
            int rightC = 2 * pos + 2;
            int parent = pos;
            // left exists and parent is larger than the left child
            if (leftC < size && weightArr[data[leftC]] < weightArr[data[parent]]){
                parent = leftC;
            }
            // right exists and the current parent is larger than the right child
            if (rightC < size && weightArr[data[rightC]] < weightArr[data[parent]]) {
                parent = rightC;
            }
            // if the parent is the smallest
            if ( parent == pos) break;
            // swap
            int temp = data[pos];
            data[pos] = data[parent];
            data[parent] = temp;
            pos = parent; // go to next level
        }
    }
};

#endif