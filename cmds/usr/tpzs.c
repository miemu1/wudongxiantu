// top.c leeyao�޸�ȥbug�汾(ԭ���汾����ж�����Ҿͳ�����)
#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{

        object *list,*ob;
        int i;
        string msg;

        ob = filter_array(children(USER_OB),(: userp($1)  :));
        list = sort_array(ob, (: top_list :));
        msg ="\n\t������ "+HIW+MUD_NAME+"ת�����а�"NOR" ��\n";
        msg += "���������Щ��������������������Щ�����������������\n";
        msg += "��  ���� ��    ��        ��          �� �� �� 			��\n";
        msg += "���������ة��������������������ة���������\n";
//        msg += "��ע����ֹ�������																			��\n";
 //       msg += "����һ����ҽ���100����㡣									��\n";
//        msg += "���ڶ�����������ҽ���50����㡣				��\n";
 //       msg += "����������ʮ����ҽ���20����㡣							��\n";
        msg += "���������ة��������������������ة���������\n";

        for (i = 0 ;i < 15 ; i++)
		{
			if( i >= sizeof(list))
                msg += sprintf("��  %-5s ��ʱ��ȱ����������������������������������\n"NOR,chinese_number(i+1));
            else
			{
				if(list[i] == me)
					msg += HIC BBLK;
					msg += sprintf("��  %-5s%-22s\n"NOR,chinese_number(i+1),"\t				\t\t"+list[i]->query("name")+"\t\t\t\t\t\t				[ "+list[i]->query("zhuanshi")+"�� ]");
            }
        }
        msg += "������ʦ�����ߡ�˯�ߡ����Ծ�������������\n";
        msg += "  " + NATURE_D->game_time() + "�ǡ�\n";
		msg = replace_string(msg,"\n",ZJBR)+"\n";
		write(ZJOBLONG+msg+"\n");
       // write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score(ob1);
	score2 = get_score(ob2);

    return score2 - score1;
}

int get_score(object ob)
{
        int score;
        score = ob->query("zhuanshi");
        return score;
}

int help(object me)
{
write(@HELP
ָ���ʽ : top

���ָ���������֪������ʮ���������Щ����ȥ�����ǡ�

HELP
    );
    return 1;
}

