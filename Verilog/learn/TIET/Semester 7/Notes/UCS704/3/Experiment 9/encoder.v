module encoder(e,y3,y2,y1,y0,a1,a0);
    input e,y3,y2,y1,y0;
    output a1,a0;
    assign a0 = e&(y1|y3);
    assign a1 = e&(y3|y2);
endmodule