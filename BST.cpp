/*
 * BST.cpp
 *
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

#include "BST.h"
//#include "WordPair.h"
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"

template <class ElementType>
bool BST<ElementType>::insertR(const ElementType& element, BSTNode<ElementType>* current) throw(ElementAlreadyExistsInBSTException){
	if (element == current->element){
		throw ElementAlreadyExistsInBSTException("element already exists");
		return false;
	}
	else if (current->element < element){
		if (current->hasRight()){
			return insertR(element, current->right);
		}
		else{
			BSTNode<ElementType>* newNode = new BSTNode<ElementType>(element);
			current->right = newNode;
			return true;
		}
	}
	else{
		if (current->hasLeft()){
			return insertR(element, current->left);
		}
		else{
			BSTNode<ElementType>* newNode = new BSTNode<ElementType>(element);
			current->left = newNode;
			return true;
		}
	}
}

template <class ElementType>
ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException){
	if (targetElement == current->element){
		return current->element;
	}
	else if (current->element < targetElement){
		if (current->hasRight()){
			return retrieveR(targetElement, current->right);
		}
		else{
			throw ElementDoesNotExistInBSTException("element does not exist");
		}
	}
	else{
		if (current->hasLeft()){
			return retrieveR(targetElement, current->left);
		}
		else{
			throw ElementDoesNotExistInBSTException("element does not exist");
		}
	}
}

template <class ElementType>
void BST<ElementType>::traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const{
	if (current->hasLeft()){
		traverseInOrderR(visit, current->left);
	}
	visit(current->element);
	if (current->hasRight()){
		traverseInOrderR(visit, current->right);
	}
}

template <class ElementType>
BST<ElementType>::BST(){                               // Default constructor
	BSTNode<ElementType>* newNode = new BSTNode<ElementType>;
	root = newNode;
	elementCount = 0;
}

template <class ElementType>
BST<ElementType>::BST(ElementType& element){           // Parameterized constructor
	BSTNode<ElementType> newNode = BSTNode<ElementType>(element);
	root = newNode;
	elementCount = 1;
}

template <class ElementType>
BST<ElementType>::BST(const BST<ElementType>& aBST){   // Copy constructor

}

template <class ElementType>
BST<ElementType>::~BST(){                              // Destructor

}

 // Time efficiency: O(1)
template <class ElementType>
int BST<ElementType>::getElementCount() const{
	return elementCount;
}

// Time efficiency: O(log2 n)
template <class ElementType>
void BST<ElementType>::insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException){
	if (elementCount == 0){
		BSTNode<ElementType>* newNode = new BSTNode<ElementType>(newElement);
		root = newNode;
		elementCount++;
	}
	else if (root->element == newElement){
		throw ElementAlreadyExistsInBSTException("element already exists");
	}
	else{
		bool insertSuccessful = insertR(newElement, root);
		if (insertSuccessful){
			elementCount++;
		}
	}
}

// Time efficiency: O(log2 n)
template <class ElementType>
ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException){
	if (elementCount == 0){
		throw ElementDoesNotExistInBSTException("element does not exist");
	}
	else if (root->element == targetElement){
		return root->element;
	}
	else{
		return retrieveR(targetElement, root);
	}
}

// Time efficiency: O(n)
template <class ElementType>
void BST<ElementType>::traverseInOrder(void visit(ElementType&)) const{
	if (elementCount != 0){
		traverseInOrderR(visit, root);
	}
}
