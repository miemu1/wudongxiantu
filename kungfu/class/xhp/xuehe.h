// mojiao.h

int permit_recruit(object ob)
{
object me;

me = this_object();

if (ob->query("detach/Ѫ����"))
{
message_vision("$N��ŭ������Ѫ������������Ҫ��������Ҫ�߱��ߣ�\n",me);
return 0;
}
if (ob->query("betrayer/times"))
{
command("say Ѫ���ɽ����ľ������壬������ʦ֮��������⣿");
return 0;
}
if( ob->query("family/family_name") &&
 ob->query("family/family_name") != "Ѫ����" )
{
command("say ���������ʦָ�㣬��Ҫ���¿๦����Ҫ���Ķ��⣡");
return 0;
}
return 1;
}

