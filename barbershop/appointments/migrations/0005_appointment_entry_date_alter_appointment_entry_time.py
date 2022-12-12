# Generated by Django 4.1.3 on 2022-12-05 07:13

from django.db import migrations, models
import django.utils.timezone


class Migration(migrations.Migration):

    dependencies = [
        ('appointments', '0004_alter_appointment_entry_time'),
    ]

    operations = [
        migrations.AddField(
            model_name='appointment',
            name='entry_date',
            field=models.DateField(default=django.utils.timezone.now),
            preserve_default=False,
        ),
        migrations.AlterField(
            model_name='appointment',
            name='entry_time',
            field=models.TimeField(),
        ),
    ]