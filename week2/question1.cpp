class Exp {
public:
    virtual int eval() = 0;
    virtual ~Exp() = default;
};

class IntLit : public Exp {
    int value;
public:
    IntLit(int v) : value(v) {}
    int eval() override { return value; }
};

class BinExp : public Exp {
    Exp* left;
    Exp* right;
    char op;
public:
    BinExp(Exp* l, char o, Exp* r) : left(l), right(r), op(o) {}

    int eval() override {
        int leftVal = left->eval();
        int rightVal = right->eval();

        switch (op) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return rightVal != 0 ? leftVal / rightVal : 0;
            default: return 0;
        }
    }

    ~BinExp() {
        delete left;
        delete right;
    }
};

class UnExp : public Exp {
    Exp* exp;
    char op;
public:
    UnExp(char o, Exp* e) : exp(e), op(o) {}

    int eval() override {
        int expVal = exp->eval();
        return (op == '-') ? -expVal : expVal;
    }

    ~UnExp() {
        delete exp;
    }
};