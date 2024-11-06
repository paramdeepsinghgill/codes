module mux_tb();
    reg e,a,b,c,d,s1,s2;
    wire y;
    mux m(e,s1,s2,a,b,c,d,y);
    initial begin
        $monitor("e = %b | s1 = %b s2 = %b | a = %b b = %b c = %b d = %b | y = %b",e, s1,s2,a,b,c,d,y);
    end
    initial begin
        e = 0; a=0; b=0; c=0; d=0; s1=0; s2=0;
		#5 e = 1; a=0; b=0; c=0; d=0; s1=0; s2=0;
		#5 e = 1; a=0; b=0; c=0; d=1; s1=0; s2=1;
		#5 e = 1; a=0; b=0; c=1; d=0; s1=1; s2=0;
		#5 e = 1; a=0; b=0; c=1; d=1; s1=1; s2=1;
		#5 e = 1; a=0; b=1; c=0; d=0; s1=0; s2=0;
		#5 e = 1; a=0; b=1; c=0; d=1; s1=0; s2=1;
		#5 e = 1; a=0; b=1; c=1; d=0; s1=1; s2=0;
		#5 e = 1; a=0; b=1; c=1; d=1; s1=1; s2=0;
		#5 e = 1; a=1; b=0; c=0; d=0; s1=0; s2=1;
		#5 e = 1; a=1; b=0; c=0; d=1; s1=0; s2=0;
    end
endmodule