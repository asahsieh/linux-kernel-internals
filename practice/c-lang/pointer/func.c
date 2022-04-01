int main() {
    typedef void (*funcptr)();
    (* (funcptr) (void *) 0)();
}
