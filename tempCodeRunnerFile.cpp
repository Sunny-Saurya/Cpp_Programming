int i = 0;
    int flag = 1;
    
    while (n != 0)
    {
        if (n == pow(2, i))
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }