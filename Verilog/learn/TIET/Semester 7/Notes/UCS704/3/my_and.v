module myand(o,a,b);
output o;
input a,b;
assign o=a&b;   	
endmodule


// simulation
module simand;
reg a,b;
wire o;
myand ma(o,a,b);

initial begin
     $dumpfile("simand.vcd");
     $dumpvars(0,simand);
     $monitor("a=%d,b=%d,o=%d\n",a,b,o);
        a = 1'b0;    b = 1'b0; 
     #10
        a = 1'b1; b = 1'b1;
     #10  
       a = 1'b0; b = 1'b1; 
     #10
        a = 1'b1; b = 1'b0;
#10
$finish;
   end
endmodule