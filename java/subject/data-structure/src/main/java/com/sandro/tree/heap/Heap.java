package com.sandro.tree.heap;

import lombok.AccessLevel;
import lombok.AllArgsConstructor;
import lombok.Getter;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@AllArgsConstructor(access = AccessLevel.PRIVATE)
public class Heap {
    private final List<Integer> list;

    public static Heap of(int... values) {
        return new Heap(Arrays.stream(values).boxed().collect(Collectors.toList()));
    }

    public boolean isHeap() {
        int lastIndexOfList = list.size() - 1;
        for (int i = lastIndexOfList; i >= 0; i--)
            if (hasGreaterChild(i))
                return false;
        return true;
    }

    private boolean hasGreaterChild(int i) {
        Integer tempValue = list.get(i);
        if (hasRight(i)) {
            Integer left = list.get(i * 2 + 1);
            Integer right = list.get(i * 2 + 2);
            return tempValue < left || tempValue < right;
        }
        if (hasLeft(i)) {
            Integer left = list.get(i * 2 + 1);
            return tempValue < left;
        }
        return false;
    }

    public void makeHeap() {
        for (int i = list.size() - 1; i >= 0; i--)
            heapifyDown(i);
    }

    private void heapifyDown(int i) {
        if (isNotLeaf(i)) {
            Node tempNode = getTempNode(i);
            Node leftNode = getLeftNode(i);
            Node rightNode = getRightNode(i);

            Node maxChild = max(leftNode, rightNode);

            if (tempNode.smallerThan(maxChild))
                heapifyDown(swap(tempNode, maxChild));
        }
    }

    private boolean hasRight(int i) {
        int rightIndex = i * 2 + 2;
        int lastIndexOfList = list.size() - 1;
        return rightIndex <= lastIndexOfList;
    }

    private boolean hasLeft(int i) {
        int leftIndex = i * 2 + 1;
        int lastIndexOfList = list.size() - 1;
        return leftIndex <= lastIndexOfList;
    }

    private boolean isNotLeaf(int i) {
        return hasLeft(i);
    }

    private Node getTempNode(int i) {
        return Node.of(list.get(i), i);
    }

    private Node getLeftNode(int i) {
        int leftIndex = i * 2 + 1;
        return Node.of(list.get(leftIndex), leftIndex);
    }

    private Node getRightNode(int i) {
        int rightIndex = i * 2 + 2;
        return Node.of(list.get(rightIndex), rightIndex);
    }

    private Node max(Node node1, Node node2) {
        return node1.getValue() > node2.getValue()
                ? node1
                : node2;
    }

    private int swap(Node tempNode, Node maxChild) {
        list.set(tempNode.getIndex(), maxChild.getValue());
        list.set(maxChild.getIndex(), tempNode.getValue());
        return maxChild.getIndex();
    }

}

@Getter
@AllArgsConstructor(access = AccessLevel.PRIVATE)
class Node {
    private int value;
    private int index;

    public static Node of(int value, int index) {
        return new Node(value, index);
    }

    public boolean smallerThan(Node maxChild) {
        return value < maxChild.getValue();
    }
}
