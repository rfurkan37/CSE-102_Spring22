int isNumber(int len, char *str)
{
    if(str + 1 == '\0')
        return 1;
    else if(str[0]< '0' || str[0] > '9')
        return 0;
    else
        return isNumber(len, str + 1);
}