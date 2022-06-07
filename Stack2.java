public class Stack2 {
    public Node head = null;

    //node in linked list
    static class Node{
        int data;
        Node next;
    

    //constructor is used to create new node
    //and Next is by default initialized as null
    Node(int d){
        data = d;
        next = null;
    }//end of constrcutor
    }//end of class Node

    public void push_operation(int d){
        Node old = head;
        head = new Node(d);
        head.data = d;
        head.next = old;
    }
    public int pop_operation(){
        if(head == null){
            System.out.println("Linked list is empty");
            System.exit(1);
        }

        int value = head.data;
        head = head.next;

        return value;
    }
    public void displayStackAsLinkedList(){
        Node node = head;

        while(node!=null){
            System.out.println(node.data);
            node = node.next;
        }
    }

    public void peek(){
        int value = head.data;
        System.out.println("this is the last value "+ value);
    }

    public static void main(String[] aStrings){
        Stack2 obj = new Stack2();

        obj.push_operation(10);
        obj.push_operation(20);
        obj.push_operation(30);
        obj.push_operation(40);
        obj.push_operation(50);

        System.out.println("Dislpay elements of the Stack: ");
        obj.displayStackAsLinkedList();

        obj.pop_operation();

        System.out.println("\nDisplay elements after pop");
        obj.displayStackAsLinkedList();

        obj.peek();
    }

}
