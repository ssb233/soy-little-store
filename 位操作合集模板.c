//位操作合集； 

int makeBitOp(int low, int high)
{
    return ((1 << (high - low + 1)) - 1) << low;
}

int clearZero(int num, int low, int high)
{
    return num & (~makeBitOp(low, high));
}

int setOne(int num, int low, int high)
{
    return num | makeBitOp(low, high);
}

int flip(int num, int low, int high)
{
    return num ^ makeBitOp(low, high);
} 
