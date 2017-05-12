package day9;

//Liang Xing
//Assignment #9

public class IntegerQueue {
	
	private class ListNode{
		protected int data;
		protected ListNode next;
		
		public ListNode(int n){
			this.data = n;
		}
	}
	private ListNode front;
	public IntegerQueue(){
		this.front = null;
	}
	public void clear(){
		this.front = null;
	}
	public boolean isEmpty(){
		if(this.front == null)
			return true;
		return false;
	}
	public int size(){
		ListNode current = this.front;
		int count = 0;
		while(current != null){
			count++;
			current = current.next;
		}
		return count;
	}
	public void offer(int n){
		if(this.isEmpty()){
			ListNode node =new ListNode(n);
			node.next = null;
			this.front = node;
		}
		else{
			ListNode current = this.front;
			while(current.next != null)
				current = current.next;
			ListNode back = new ListNode(n);
			back.next = null;
			current.next = back;
		}
	}
	public int poll(){
		if(!this.isEmpty()){
			ListNode current = this.front;
			this.front = current.next;
			return current.data;
		}
		return 0;
	}
}
