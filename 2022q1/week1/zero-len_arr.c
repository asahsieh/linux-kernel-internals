struct line {
    int length;
    char contents[];
};

// Valid: recursively declare the struct which has flexible array member
union multi_line {
    struct line l;
};

// Invalid
// Comiling err from GCC: flexible array member in union
union uni_line {
    int length;
    char contents[];
};

// Valid?
union uni_line uni_line_arr[10];
