// miss ׷Ѱ��Ʒ

#include <ansi.h>

inherit F_CLEAN_UP;
string *anjian=({

//"�������:who",
"ħ�߸���:flygo moku",
"�þ�����:flygo huanjing",

//"��������:flygo caoren",
});
mapping where=([
//"qiandao":"/d/city/wumiao",
//"daizi":"/d/wizard/guest_room",
//"room":"/data/hell/4/guangchang",
//"lunjian" : "/d/lunjian/enter",
//"turen" : "/d/pk/entry",
//"qianchi" : "/d/fuben/qianchipu/qianchipu",
]);
int main(object me, string str)
{
	if(environment(me)->query("no_magic", 1))
		return notify_fail("�����޷�ʹ��������ܡ�\n");
	
 if(!str)
 {
string bynb,msg,bynb1;
msg=ZJOBLONG"���¹��ܼ�����ѡ��\n"ZJOBACTS2+ZJMENUF(4,4,8,30);
  foreach (bynb in anjian)
 msg+= bynb+ZJSEP;
 msg+="���˸���:flygo caoren\n";
 //msg+= bynb1+ZJSEP;

 tell_object(me,msg);
 return 1;
 }

	if (me->is_ghost())
		return notify_fail("�㻹�ǵȻ�������˵�ɡ�\n");
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	if (me->is_fighting())
		return notify_fail("������ս���С�\n");

    {	//����
    	object room;
    	
        if (str == "moku")
        {
        	if(!objectp(room = new("/d/fuben_moku/moku")))
        	{
        		write("��������ʧ�ܡ�\n");
        		return 1;
        	}
        	if(!room->start_fuben_moku(this_player()))
        		destruct(room);
        	return 1;
        }
        if (str == "caoren")
        {
        	if(!objectp(room = new("/d/fuben_caoren/shilianchang")))
        	{
        		write("��������ʧ�ܡ�\n");
        		return 1;
        	}
        	if(!room->start_fuben_caoren(this_player()))
        		destruct(room);
        	return 1;
        }
        
        if (str == "huanjing")
        {
            "/d/fuben_huanjing/huanjing"->start_fuben(me);
            return 1;
        }
    }

 if (stringp(where[str]))
 me->move(where[str]);
return 1;	
}

int help(object me)
{
write(@HELP
ָ���ʽ :
��ħţ�ƣ�
HELP
    );
    return 1;
}
