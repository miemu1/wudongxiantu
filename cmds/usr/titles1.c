// special

#include <ansi.h>
#define TITLE_D "/adm/daemons/titled.c"
inherit F_CLEAN_UP;
int reach_player(object me,string title);

int main(object me, string arg)
{
	string msg,fmsg;
	mapping ss;
	string title;
	object ob;
	string pro,sname;
	int i,z;
	if (wizardp(me) && stringp(arg) &&
	    objectp(ob = find_player(arg)))
		// �鿴������ҵ����⼼��
		arg = 0;
	else
		ob = me;

	pro = (ob == me) ? "��" : ob->name(1);

	if (! ob->query("born"))
		return notify_fail(pro + "��û�г����ţ�������ʲô�ɾ��أ�\n");
    if (arg&&sscanf(arg,"%s==%s",msg,title) >= 2&&msg=="buy")
	{ 
      TITLE_D->buy_title(me,title);
	  return 1;
	}
	
	if (arg&&sscanf(arg,"%s==%s",msg,title) >= 2&&msg=="eee")
	{ 
      TITLE_D->use_title(me,title);
	  return 1;
	}
     if (! mapp(ss = TITLE_D->alltitles())|| ! sizeof(ss))
		 	return notify_fail(pro + "���ں���ʲô�ɾͶ�û��Ŷ���ȴ��з��ɡ�\n");
		
     if(!arg)
	 {msg= ZJOBLONG+"�ڽ�����Ŀǰ����ͨ��Ŭ����ȡ�ĳɾ����£�\n"NOR;
		msg+=ZJOBACTS2+ZJMENUF(2,2,10,38);
		foreach (title in keys(ss))
		{ 
		fmsg =HIC+title+NOR;
		fmsg+=me->query("titles/"+title)?"["HIY"�ѻ�ȡ"NOR"]":"["HIR"δ��ȡ"NOR"]";
		msg+=fmsg+":titles1 "+title+ZJSEP;
		}
		msg +="\n";
		write(msg);
		return 1;
	    }
		else
			if(arg && (ob == me))
		{
          if(me->is_busy())
          return notify_fail("������æ���أ���������ɾ�\n");
	      title = arg;
		  if (!ss[title])
			  return notify_fail("��û������ɾ�\n");
		  msg=ZJOBLONG+TITLE_D->query_title(me,title);
		  msg = replace_string(msg,"\n",ZJBR)+"\n";
		  msg+=ZJOBACTS2+ZJMENUF(1,1,10,38);
		  msg+="����ɾ�:titles2 "+title+ZJSEP;
		  msg+="����ɾ�:titles1 buy=="+title;
		  //msg+="���ؽ���"":titles1";
		}
		msg += "\n";
		write(msg);
		return 1;
        }

	int reach_player(object me,string title)
	{
		
		if(me->query("titles/"+title))
			return 1;

		
		return 0;
		
		
    }
	
int help(object me)
{
write(@HELP
ָ���ʽ : titles1 <title> | <���ID>

ʹ������������Բ鿴��ĳɾ͡�

HELP );
    return 1;
}
