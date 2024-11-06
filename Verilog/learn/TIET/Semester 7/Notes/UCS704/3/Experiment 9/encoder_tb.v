module encoder_tb();
    reg e,y3,y2,y1,y0;
    wire a1,a0;
    encoder en(e,y3,y2,y1,y0,a1,a0);
    initial begin
        $monitor("e = %b | y3 = %b y2 = %b y1 = %b y0 = %b | a1 = %b a2 = %b", e,y3,y2,y1,y0,a1,a0);
    end
    initial begin
        e = 0; y3 = 0; y2 = 0; y1 = 0; y0 = 1;
        #5 e = 1; y3 = 0; y2 = 0; y1 = 0; y0 = 1;
        #5 e = 1; y3 = 0; y2 = 0; y1 = 1; y0 = 0;
        #5 e = 1; y3 = 0; y2 = 1; y1 = 0; y0 = 0;
        #5 e = 1; y3 = 1; y2 = 0; y1 = 0; y0 = 0;
    end
endmodule