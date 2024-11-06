module andGate;
    reg a,b;
    wire c;
    assign c = a&b;
    initial begin
        a = 1;
        b = 0;
        #10
        $display("a = %b b = %b c = %b", a,b,c);
        $finish;
    end
endmodule
