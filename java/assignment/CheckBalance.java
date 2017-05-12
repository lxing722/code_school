package day8;

//Liang Xing
//Assignment #8

public class CheckBalance {
	
	private String input;
	private int index;
	public CheckBalance(String input){
		this.input = input;
	}
	public boolean balanced(){
		ArrayStack stack = new ArrayStack();
		int i=0;
		while(i<this.input.length()){
			char temp = this.input.charAt(i);
			if(temp=='{'||temp=='['||temp=='('||temp=='<'){
				stack.push(temp);
			}
			if(temp=='}'||temp==']'||temp==')'||temp=='>'){
				if(stack.isEmpty()){
					this.index = i;
					return false;
				}					
				else{
					char temp1 = stack.pop();
					if((temp=='}'&&temp1!='{')||(temp==']'&&temp1!='[')||(temp==')'&&temp1!='(')||(temp=='>'&&temp1!='<')){
						this.index = i;
						return false;
					}
				}
			}
			i++;
		}
		this.index = i;
		if(!stack.isEmpty())
			return false;
		return true;
	}
	public int index(){
		return this.index;
	}
}
