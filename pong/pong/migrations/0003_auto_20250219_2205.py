# Generated by Django 3.2.25 on 2025-02-19 22:05

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pong', '0002_gamestats'),
    ]

    operations = [
        migrations.AddField(
            model_name='gamestats',
            name='user2',
            field=models.CharField(default='none', max_length=100),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='gamestats',
            name='user3',
            field=models.CharField(default='none', max_length=100),
            preserve_default=False,
        ),
    ]
