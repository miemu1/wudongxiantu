// MingJiao.h for all npc of mingjiao

int permit_recruit(object ob)
{
        if( ob->query("detach/����") || 
            ob->query("betrayer/����") )
        {
                command("say �뿪�����̾Ͳ�Ҫ�ٻ�����");
                return 0;
        }

        if( ob->query("betrayer/times") )
        {
                command("say ���²��Ҳ��ţ�����������޵ľ����������ˡ�");
                return 0;
        }

        if( ob->query("family/family_name") && 
            ob->query("family/family_name") != "����" )
        {
                command("say ������ʦ�����Ͳ�Ҫ�����������ˣ�");
                return 0;
        }

        return 1;
}

/*
int recognize_apprentice(object ob, string skill)
{
        object me = this_object();
        mapping ob_fam;

        if( !(ob_fam=query("family", ob)) || ob_fam["family_name"] != "����" )
        {
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return -1;
        }

        if( ob_fam["generation"] <= query("family/generation", me) )
        {
                return 1;
        }

        return 0;
}
*/
