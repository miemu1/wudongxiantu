// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;
//修改铠甲描述
int main(object me,string arg)
{
    string cishu;
    object kaijia;
    if(!arg)
    {    
    if(!me->query("kaijias"))
    return notify_fail("你还没有铠甲呢！\n");
    return notify_fail(INPUTTXT("请输入", "kaijialong $txt#") + "\n");	
    }
    if(!me->query("kaijias"))
    return notify_fail("你还没有铠甲呢！\n");
    if (me->query("yuanbao") < 1000)
	return notify_fail("你钱庄存款不足，不能进行修改名字，需要1000灵石！\n");
    if (sscanf(arg,"%s",cishu) != 1)     
	return 1;	
    kaijia->set("name",cishu);
    me->add("yuanbao",-1000);
    write(HIC"更改完成\n"NOR);
	
}
