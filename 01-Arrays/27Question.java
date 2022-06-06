// Largest Rectangle in Histogram

// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Application of Stack

import java.util.*;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int[] left = new int[heights.length];
        
        int width = 0;
        int ans = 0;
        int area = 0;
        Stack<Integer> stack = new Stack<>();
        
        for(int i = 0; i<heights.length; i++){
            
            while(!stack.isEmpty() && heights[i] <= heights[stack.peek()]){
                
                stack.pop();
                
            }
            
            if(stack.isEmpty()){
                left[i] = -1;
            }
            else{
                left[i] = stack.peek();
            }
            stack.add(i);
        }
        
        
        stack.clear(); // clearing stack for right bound
        
        int[] right = new int[heights.length];
        for(int i = heights.length-1; i>= 0; i--){
            
            while(!stack.isEmpty() && heights[i] <= heights[stack.peek()]){
                
                stack.pop();
                
            }
            
            if(stack.isEmpty()){
                right[i] = heights.length;
            }
            else{
                right[i] = stack.peek();
            }
            stack.add(i);
        }
        
        
        for(int i = 0; i<heights.length; i++){
            
            width = right[i] - left[i] - 1;
            area = heights[i]*width;
            
            ans = Math.max(area,ans);
            
            
        }
        return ans;
    }
}