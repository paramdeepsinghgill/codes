module mux(e,s1,s2,a,b,c,d,y);
	input e,s1,s2,a,b,c,d;
	output y;
	assign y = e&(~s1&~s2&a || ~s1&s2&b || s1&~s2&c || s1&s2&b);
endmodule