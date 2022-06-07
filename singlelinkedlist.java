//import SLL1.Node;

public class singlelinkedlist{
    public class node {
      
          int data;
          node next;
  
          public node(int d){
              this.data = d;
              this.next = null;
          }
      }
  
      public node head = null;
      public node tail = null;
  
      public void insertNode(int d){
          node newnode = new node(d);
          if (head == null){
              head = newnode;
          }
          else {
              node node = head;
              while (node.next !=null){
                  node = node.next;
              }
              node.next = newnode;
          }
          tail = newnode;
      }
      public void insertFirst(int d){
          node newnode = new node(d);
  
          if (head==null){
              head = newnode;
              return;
          }
          newnode.data = d;
          newnode.next=null;
          newnode.next=head;
          head = newnode;
      }
  
      public void insertLast(int d){
          node lastnode = new node(d);
          node currentnode = head;
  
          while(currentnode.next !=null){
              currentnode = currentnode.next;
          }
          currentnode.next = lastnode;
      }
  
  
      public void displaysinglelinkedlist(){
          node node = head;
          while(node.next!=null){
              System.out.println(node.data);
              node = node.next;
          }
          System.out.println(node.data);
      }

      public void insertAtLocation(int loc, int d){
          node currentnode = new node(d);
          currentnode.next = null;

          /*if LL is empty*/
          if(head == null){
              insertFirst(d);
              return;
          }
          //for traverse
          node tmp = head;

          /*i = 0 */
          for(int i = 0;i<loc - 1;i++){
              tmp = tmp.next;
          }
          currentnode.next = tmp.next;
          tmp.next = currentnode;
      }
      //delete the first node
     public void delFirstNode(){
         if(head == null){
             System.out.println("Empty list");
             return;
         }
         head = head.next;
     }
     //delete last node
      public static void main(String[] args) {
          singlelinkedlist list = new singlelinkedlist();
          list.insertNode(12);
          list.insertNode(10);
          list.insertNode(8);
          list.insertNode(109);
          list.insertNode(13);
          list.insertNode(17);
  
          // inserting first node
          list.insertFirst(23);
  
          // inserting last node    
          list.insertLast(255);

          list.insertAtLocation(7, 1);
  
          list.displaysinglelinkedlist();
      }
  
  }
  