package day10;

//Liang Xing
//Assignment #10

import java.util.*;
public class AssassinManager {
	
	private AssassinNode kill_ring;
	private AssassinNode graveyard;
	
	public AssassinManager(Scanner input){
		if(input.hasNextLine()){
			AssassinNode temp = new AssassinNode(input.nextLine());
			this.kill_ring = temp;
		}
		else
			throw new IllegalArgumentException();
		if(input.hasNextLine()){
			AssassinNode previous = this.kill_ring;
			while(input.hasNextLine()){
				AssassinNode temp1 = new AssassinNode(input.nextLine());
				previous.next = temp1;
				previous = temp1;
			}
		}
		this.graveyard = null;
	}
	public void printKillRing(){
		if(!this.gameOver()){
			AssassinNode current = this.kill_ring;
			while(current.next != null){
				System.out.println(current.name+" is stalking "+current.next.name);
				current = current.next;
			}
			System.out.println(current.name+" is stalking "+this.kill_ring.name);
		}
	}
	public void printGraveyard(){
		AssassinNode current = this.graveyard;
		while(current != null){
			System.out.println(current.name+" was killed by "+current.killer);
			current = current.next;
		}
	}
	public boolean killRingContains(String name){
		AssassinNode current = this.kill_ring;
		while(current != null && !current.name.equals(name))
			current = current.next;
		if(current != null)
			return true;
		return false;
	}
	public boolean graveyardContains(String name){
		AssassinNode current = this.graveyard;
		while(current != null && !current.name.equals(name))
			current = current.next;
		if(current != null)
			return true;
		return false;
	}
	public boolean gameOver(){
		if(this.kill_ring.next == null)
			return true;
		return false;
	}
	public String winner(){
		if(this.gameOver())
			return this.kill_ring.name;
		return null;
	}
	public void kill(String name){
		if(!killRingContains(name))
			throw new IllegalArgumentException();
		if(gameOver())
			throw new IllegalStateException();
		AssassinNode current_ring = this.kill_ring;
		AssassinNode previous = this.kill_ring;
		while(!current_ring.name.equals(name)){
			previous = current_ring;
			current_ring = current_ring.next;
		}				
		if(current_ring == this.kill_ring){
			this.kill_ring = current_ring.next;
			AssassinNode current = this.kill_ring;
			while(current.next != null)
				current = current.next;
			current_ring.killer = current.name;
		}
		else{
			current_ring.killer = previous.name;
			previous.next = current_ring.next;
		}
		current_ring.next = this.graveyard;
		this.graveyard = current_ring;								
	}
}
