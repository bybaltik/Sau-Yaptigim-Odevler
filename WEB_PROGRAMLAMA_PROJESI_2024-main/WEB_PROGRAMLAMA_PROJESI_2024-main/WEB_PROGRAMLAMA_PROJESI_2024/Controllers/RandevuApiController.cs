using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WEB_PROGRAMLAMA_PROJESI_2024.Data;
using WEB_PROGRAMLAMA_PROJESI_2024.Models;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class RandevuApiController : ControllerBase
    {
        private readonly ApplicationDbContext _context;

        public RandevuApiController(ApplicationDbContext context)
        {
            _context = context;
        }

        // Tüm Randevuları Listeleme
        [HttpGet]
        public IActionResult GetRandevular()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            var userRole = HttpContext.Session.GetInt32("UserRole");

            if (userId != null && userRole != null)
            {
                if (userRole == 1)
                {
                    var randevular = _context.Randevus
                .Include(r => r.Musteri)
                .Include(r => r.Calisan)
                .Include(r => r.Islem)
                .Select(r => new
                {
                    r.RandevuId,
                    MusteriAdi = r.Musteri.MusteriAdi,
                    CalisanAdi = r.Calisan.AdSoyad,
                    IslemAdi = r.Islem.IslemAdi,
                    r.Tarih,
                    r.SaatAraligi,
                    r.Onay
                }).ToList();

                    return Ok(randevular);
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                return RedirectToAction("Login", "Home");
            }
        }

        /*
        [HttpPut("{randevuId}")]
        public ActionResult OnaylaRandevu(int randevuId)
        {
            // Randevuyu veritabanında bul
            var randevu = _context.Randevus.FirstOrDefault(r => r.RandevuId == randevuId);

            if (randevu == null)
            {
                return NotFound(new { error = "Randevu bulunamadı!" });
            }

            // Randevu onayını güncelle
            randevu.Onay = true;

            _context.Randevus.Update(randevu);

            // Veritabanına değişiklikleri kaydet
            _context.SaveChanges();

            return Ok();
        }
        */
    }
}
