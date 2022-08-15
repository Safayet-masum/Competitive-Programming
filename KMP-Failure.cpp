int match[1000005];
void KMP(sSring S)
{
    int lef = 0, rig ;
    match[0] = 0 ;
    for(rig=1; rig<S.size(); rig++ )
    {
        while(lef>0&&S[lef]!=S[rig])
        {
            lef=match[lef-1]  ;
        }
        if(S[lef]==S[rig])
            lef++;
        match[rig]=lef ;
    }
}
