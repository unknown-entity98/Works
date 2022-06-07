public class SLL1 {
    
    Node head; // 'head' of the linked list
    
    // node in the Linked list is a class
    static class Node{ 
    int data;
    Node next;
    
    //constructor is used to create a new Node and Next is by default is initialized as null
    Node(int d){
          data = d;
          next = null;
    } //end of constructor
    
    } //end of static class node

public void DisplayList() {
    Node node = head;
    
    while(node!=null) {
          System.out.println("Vale at each node: "+node.data+" ");
          node = node.next;
    }
    }//end of DisplayList function

    //main method
public static void main(String[] args) {

    SLL1 LList = new SLL1(); // create an empty Linked list
    
    // create 4 nodes 
    LList.head = new Node(10);
    Node two = new Node(20);
    Node three = new Node(30);
    Node four = new Node(40);
    //four nodes allocated dynamically
    
    //link first 'head' node with node 'two'
    LList.head.next = two;
    
    //link node 'two' to node 'three'
    two.next = three;
    
    //link node 'three' to node 'four'
    three.next = four;
    
    // display value at each node
    LList.DisplayList(); // Traverse the list
    
    }//end of main method
    
    } //end of class SLL1