// walk.c

inherit F_CLEAN_UP; 

#include "/d/rw.h"
 
#define PATH_D  "/adm/daemons/pathd.c"

int main(object me, string arg)
{
        mixed a;
        mixed br;
        string str = "",*walks;
        
 /*       if( uptime() < 2100 )
                return notify_fail("ϵͳ�������̾������������2100�룬���Ժ����� ....\n");
*/
     //   if(time() - me->query_temp("last_walk") < 10 )
 //               return notify_fail("ϵͳ�������̾���������� ....\n");
 	
	if (me->is_ghost())
		return notify_fail("�㻹�ǵȻ�������˵�ɡ�\n");
 if (me->is_busy())
 return notify_fail("�㻹����ͣ����ͷ���������˵�ɣ�\n");
	if( !arg) 
		return notify_fail(INPUTTXT("����ȥ��������������,��������Ѱ�������ֱ����������������Ŀǰֻ�в���λ�ÿ�","walk $txt#")+"\n");
//		ZJOBACTS2+ZJMENUF(3,3,8,30)+"���:enforce max"ZJSEP"ȡ������:enforce none\n");

if (where[arg]&&!me->is_busy()||arg=="ʦ��")
{
string name;
if(arg=="ʦ��"&&me->query("family/master_name"))
name= where[me->query("family/master_name")];
else
name = where[arg];
me->move(name);
me->start_busy(5);
tell_object(me,"����Ϊ���ڸ�·��������������æ�Ҳ��ѣ�\n");
return 1;
}
        if( environment(me)->is_chat_room() ) return notify_fail("�������ڲ���ʹ��Ѱ·���ܣ�\n");

        if( sscanf(base_name(environment(me)), "/f/%*s") )
                return notify_fail("�������ֹʹ��walkѰ·���� ....\n");

        if( !is_chinese(arg) )
                return notify_fail("ָ���ʽ��walk <���ĵ�ַ>\n");

        me->set_temp("last_walk", time());
        a = PATH_D->search_for_path(me, arg);
        if( !a || a == 1) {
                me->set_temp("last_walk", time()+10);
                write("û������ط�����������ط������ﳬ���涨�ľ������ơ�\n");
                return 1;
        }
        write(arg+"·��������ɣ���"+sizeof(a[1])+"����·��Ϊ��\n");
        for( int i = 0;i < sizeof(a[1]);i++ )
        {
                str    += a[1][i] + ";";
        }
        str = str[0..<2]; 
        write(str+"\n");//���·��
        br = me->query("env/brief");
        me->set("env/brief", 1);
        walks = explode(str,";");
for(int i = 0;i < sizeof(walks);i++)
{
tell_object(me,ZJFORCECMD(walks[i]));//���ÿͻ���������ָ����Դﵽ��ֹ��ҽ��л����˻�ű���������Ϊ��
}
        me->set("env/brief", br);
        write("���Ѿ�����"+arg+"��\n");
       // me->force_me("maphere");
   //    tell_object(me,ZJFORCECMD("maphere -m"));
        return 1;
}

