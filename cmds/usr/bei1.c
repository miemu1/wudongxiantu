#include <ansi.h>
#include <net/dns.h>
inherit F_CLEAN_UP;
#define DEBUG "snowsot"
#ifdef DEBUG
//�޸�������Ϣ����
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
    int i;
    object *str;
    str=users();
    for (i=0;i<sizeof(str);i++)
	if (str[i]->query("id")==target){
	      if (!environment(str[i])) return 0;
	      else
	    return str[i];
	 }
    return 0;
}
int help(object me);
void create() {seteuid(getuid());}
int main(object me, string arg)
{
    string target, msg, mud;
    object obj;
   // write(arg+"\n");
    if(!arg||sscanf(arg, "%s %s", target, msg)!=2){
     target=arg;
     msg="...";
    // arg+="...";
   //  write(arg+"\n");
     //write(target+"\n");
    }
  // write(target+"\n");

    if( sscanf(target, "%s@%s", target, mud)==2 ) {
	GTELL->send_gtell(mud, target, me, msg);
	write(BOLD "��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��"NOR"\n");
	return 1;
    }
    obj = find_player(target);
    if (obj && !userp(me)){
	 write(HIY+ me->name(1) + HIG"����˵��" + msg + ""NOR"\n");
	return  1;
    }
    if (!obj) return notify_fail("û�������ҡ�\n");
    if (!me->visible(obj)) return notify_fail("û�������ҡ�\n");
    if (!interactive(obj)) return notify_fail("û�������ҡ�\n");
 
    debug(sprintf( YEL "%s(%s)����%s(%s)��%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), msg));
    if ( member_array("tell", me->query("channels"))==-1)
		me->set("channels", me->query("channels") + ({ "tell" }) );
    write(HIG "���" HIY+ obj->name(1) + HIG"˵��" + msg + ""NOR"\n");
     
    if (me->id(obj->query("env/no_tell")) )
	return notify_fail("����Ȼ��"+obj->name(1)+"��������������������˵��....��\n");
	
	 tell_object(obj,HIY+ me->name(1) + HIG"����˵��" + msg + ""NOR"\n");
    if (me->query("env/no_tan"))	 
	 tell_object(obj,INPUTTXT(HIY+me->name(1)+HIG"����˵����"+ msg +"", "bei1 "+me->query("id")+" $txt#")+"\n");	    	    
    if (query_idle(obj)>120) write(YEL+"����"+obj->name(1)+"�Ѿ�����"+query_idle(obj)/8640000+"���ӣ������������ϻش���Ӵ��\n"+NOR);
   if (in_edit(obj)) return notify_fail("���ǣ��Է��������ڱ༭������\n");
    obj->set_temp("reply", me->query("id"));
    return 1;
}