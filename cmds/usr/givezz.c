// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/clone/7yue/zanzhu1"
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", HIW"�䶯��;����"NOR);
//	CHANNEL_D->do_channel( this_object(), "sys", "����boss��");

}
int main(object me, int arg)
{
        object *ob,*players,player1,player2;
        string str,note;
        int count,num,rdm,n,i;
         int m;
        int bmoney,avmoney,lfmoney;
        
        if  (!wizardp(me))
        return  notify_fail("��û��Ȩ��ʹ�����ָ�\n");
        if (! arg) 

        return notify_fail(INPUTTXT("�����뷢�ź�����(�ƽ�)Ȼ������(Ĭ�Ϲ�ϲ����)���磺50 ���","givezz $txt#")+"\n");
                note="��ϲ���ƣ�";
              sscanf(arg, "%d %s", count,note);
              if(me->query("balance")*10<count) return notify_fail("���Ǯ�����ˣ��Ͽ�ȥ����ʦpy���ף�\n");

        if (count<0) return notify_fail("�����ñ��˸��㵹��Ǯ�𣿣���\n");

        if (count<50) return notify_fail("��Ҳ̫С���˰ɡ�\n");

//              CHANNEL_D->do_channel(this_object(),"Ц��",
 //              ""+ HIW + ZJSIZE(24)+HIR"����������ʦ����ȡ2021.9.16ά������"+HIC"��"NOR);
//              CHANNEL_D->do_channel(this_object(),"Ц��",
//               ""+ HIW + ZJSIZE(24)+HIR"����������ʦ����ȡ2021.9.16ά������"+HIC"��"NOR);
	CHANNEL_D->do_channel(this_object(), "chat", ZJSIZE(27)+BLK HBCYN"��ݴ�������ʼ�����");
//	CHANNEL_D->do_channel(this_object(), "chat", ZJSIZE(27)+BLK HBCYN"����ڿ���Ѱ�������������һ����ʮ���н�����");

               num = sizeof(users());

               players = users();

               ob = allocate(num);
               count *= 10000;

        str=sprintf("����%dλ����յ�ѶϢ��\n",sizeof(users()));
        tell_object(me,str);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��giveall ��Ʒ·��

�����ߵ�������Һ����
HELP
        );
        return 1;
}
