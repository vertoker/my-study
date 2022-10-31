from django.db import models
from django.urls import reverse
from django.contrib.postgres.fields import ArrayField
from django import forms

class Appointment(models.Model):
    haircut = models.ForeignKey("haircuts.Haircut", on_delete=models.PROTECT, null=True)
    user = models.ForeignKey("users.User", on_delete=models.PROTECT, null=True)

    def get_absolute_url(self):
        return reverse('appointments_detail', args=[str(self.id)])