/*
 * BST.h
 *
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

#pragma once

#include "BSTNode.h"
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"


template <class ElementType>
class BST {

private:
	BSTNode<ElementType>* root;
    int elementCount;

    // Utility methods
    bool insertR(const ElementType& element, BSTNode<ElementType>* current) throw(ElementAlreadyExistsInBSTException);
    ElementType& retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException);
	void traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const;
	int nodeCountR(BSTNode<ElementType>* current) const;
	ElementType& minR(BSTNode<ElementType>* current) const;
	ElementType& maxR(BSTNode<ElementType>* current) const;
	int duplicateR(const ElementType& targetElement, BSTNode<ElementType> * current);
	BSTNode<ElementType>* removeR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException);

public:
    // Constructors and destructor:
	BST();                               // Default constructor
    BST(ElementType& element);           // Parameterized constructor
	BST(const BST<ElementType>& aBST);   // Copy constructor
    ~BST();                              // Destructor

    // BST operations:

	int nodeCount() const;
	ElementType& min() const throw(ElementDoesNotExistInBSTException);
	ElementType& max() const throw(ElementDoesNotExistInBSTException);
	int duplicate(const ElementType& targetElement);
	void remove(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException);

    // Time efficiency: O(1)
	int getElementCount() const;

	// Time efficiency: O(log2 n)
	void insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException);

	// Time efficiency: O(log2 n)
	ElementType& retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException);

	// Time efficiency: O(n)
	void traverseInOrder(void visit(ElementType&)) const;

}; // end BST

#include "BST.cpp"
