# Generated by Django 4.1.2 on 2022-11-22 10:25

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('appointments', '0002_alter_appointment_user'),
    ]

    operations = [
        migrations.RenameField(
            model_name='appointment',
            old_name='start_time',
            new_name='entry_time',
        ),
    ]
