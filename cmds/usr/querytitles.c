// special

#include <ansi.h>
#define TITLE_D  "/adm/daemons/titled.c"
inherit F_CLEAN_UP;
int reach_player(object me,string title);
int main(object me, string arg)
{
	string  msg,fmsg;
	mapping ss;
	string  title;
	object ob;
	string pro,sname;
	int i;
       
	if (wizardp(me) && stringp(arg) &&
	    objectp(ob = find_player(arg)))
		// �鿴������ҵ����⼼��
		arg = 0;
	else
		ob = me;

	pro = (ob == me) ? "��" : ob->name(1);

	if (! ob->query("born"))
		return notify_fail(pro + "��û�г����ţ�������ʲô�ɾ��أ�\n");
		
           if (arg&&sscanf(arg, "%s==%s", msg, title) >= 2&&msg=="buy")
            {
			TITLE_D->buy_title(me,title);
			return 1;
			}

          if  (arg&&sscanf(arg, "%s==%s", msg, title) >= 2&&msg=="reach")
        {
        object player,*players;
        players = filter_array(users(),(: reach_player :),title);
        
       if (!sizeof(players))
        return notify_fail(title+"�ɾͻ�û���κ���Ҵ��\n");
        
    msg= ZJOBLONG+HIR "��"HIY "�䶯��;�ɾ�ϵͳ" HIR "��"NOR+ZJBR;
	msg+="Ŀǰ���������:"+title+"�ɾ�����"+sizeof(players)+"�˴��\n";
	msg+=ZJOBACTS2+ZJMENUF(3,3,9,30); 
	
	foreach (player in players)
	msg += sprintf("���ƣ�%s%s(%s):look %s%s",HIC+player->query("name")+NOR,ZJBR,HIG+player->query("id")+NOR,player->query("id"),ZJSEP);
	
	msg += HIY"���ؽ���"NOR":querytitles "+title;
	msg += "\n";
	write(msg);
			return 1;
			}
			
	if (! mapp(ss = TITLE_D->alltitles()) ||
	    ! sizeof(ss))
		return notify_fail(pro + "���ں���ʲô�ɾͶ�û��Ŷ���ȴ��з��ɡ�\n");
	
	   if (!arg)
   {
	msg= ZJOBLONG+HIR "��"HIY "�䶯��;¼�ɾ�ϵͳ" HIR "��"NOR;
	msg+="Ŀǰ����¼:"+sizeof(keys(ss))+"���ƺ�\n";
	msg+=ZJOBACTS2+ZJMENUF(2,2,9,32); 
	
	    foreach (title in keys(ss))
     {		
		fmsg =HIC"��"+title+"��"NOR;
		fmsg+=me->query("titles/"+title)?HIM"(��ӵ��)":HIR"(δӵ��)";
		msg+=fmsg+":querytitles "+title+ZJSEP;	
	 }	
		msg += "\n";	
      	write(msg);
     	return 1;
	}
	else
if (arg && (ob == me))
	{
		if (me->is_busy())
			return notify_fail("������æ���أ����ܸı�ƺš�\n");
			title = arg;					
			if (!ss[title])	
					return notify_fail("�����û������ƺ�...\n");
					 msg=ZJOBLONG+TITLE_D->query_title(me,title);
					 msg = replace_string(msg,"\n",ZJBR)+"\n"; 
 msg+=ZJOBACTS2+ZJMENUF(2,2,9,30); 
 msg+= "����ƺ�:usetitles "+title+ZJSEP;
 msg+= "�һ��ƺ�:querytitles buy=="+title+ZJSEP;
 msg+= "�������:querytitles reach=="+title+ZJSEP;
 msg+= HIY"���ؽ���"NOR":querytitles";
 }  
msg += "\n";
	write(msg);
	return 1;
}

int reach_player(object me,string title)
{

if (me->query("titles/"+title))
return 1;

return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : querytitles <title> | <���ID>

ʹ������������Բ鿴��ĳƺš�

HELP );
    return 1;
}
