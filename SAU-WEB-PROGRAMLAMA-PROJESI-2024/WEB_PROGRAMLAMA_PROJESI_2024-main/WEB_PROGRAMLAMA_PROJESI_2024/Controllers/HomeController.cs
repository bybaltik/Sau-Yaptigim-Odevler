using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;
using WEB_PROGRAMLAMA_PROJESI_2024.Data;
using WEB_PROGRAMLAMA_PROJESI_2024.Models;

namespace WEB_PROGRAMLAMA_PROJESI_2024.Controllers
{


    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly ApplicationDbContext _context; // DbContext
        public Calisan user;
        public int userRole2;
        public HomeController(ILogger<HomeController> logger, ApplicationDbContext context)
        {
            _logger = logger;
            _context = context;
        }

        public IActionResult Anasayfa()
        {
            if (userRole2 == 1)
            {
                ViewBag.Kim = 1;
                return View();
            }
            else if (userRole2 == 3)
            {
                ViewBag.Kim = 3;
                return View();
            }
            else { return View(); }
        }

        public IActionResult Tarihce()
        {
            if (userRole2 == 1)
            {
                return View();
            }
            else if (userRole2 == 3)
            {
                ViewBag.Kim = 3;
                return View();
            }
            else { return View(); }
            
        }
        public IActionResult AdminPanel()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            var userRole = HttpContext.Session.GetInt32("UserRole");

            if (userId != null && userRole != null)
            {
                // Sadece adminler bu sayfaya eriþebilir
                if (userRole == 1)
                {
                    userRole2 = 1;
                    ViewBag.Kim = 1;
                    return View();
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                ViewBag.Error = "Oturum bulunamadý. Lütfen tekrar giriþ yapýnýz.";
                return RedirectToAction("Login", "Home");
            }


        }

        public IActionResult RolEkleme()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            var userRole = HttpContext.Session.GetInt32("UserRole");

            if (userId != null && userRole != null)
            {
                // Sadece adminler bu sayfaya eriþebilir
                if (userRole == 1)
                {
                    ViewBag.Kim = 1;
                    return View();
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                ViewBag.Error = "Oturum bulunamadý. Lütfen tekrar giriþ yapýnýz.";
                return RedirectToAction("Login", "Home");
            }
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult RolEkleme(Rol rol)
        {
            // Model doðrulama kontrolü

            try
            {
                // Yeni rol kaydýný veritabanýna ekleme
                _context.Rols.Add(rol);

                // Veritabanýna deðiþiklikleri kaydetme
                _context.SaveChanges();

                // Baþarý mesajýný TempData ile saklama
                TempData["SuccessMessage"] = "Rol baþarýyla eklendi!";

                // Rol listeleme veya baþka bir sayfaya yönlendirme
                return RedirectToAction("AdminPanel");
            }
            catch (Exception ex)
            {
                // Hata durumunda loglama (opsiyonel)
                _logger.LogError("Rol eklenirken bir hata oluþtu: " + ex.Message);

                // Hata mesajýný TempData ile saklama
                TempData["ErrorMessage"] = "Bir hata oluþtu: " + ex.Message;

                // Hata durumunda ayný form sayfasýna geri dönme
                return View(rol);
            }


            // Model geçersizse ayný sayfaya geri dön
            return View(rol);
        }


        public IActionResult SalonEkleme()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            var userRole = HttpContext.Session.GetInt32("UserRole");

            if (userId != null && userRole != null)
            {
                // Sadece adminler bu sayfaya eriþebilir
                if (userRole == 1)
                {
                ViewBag.Kim = 1;
                    return View();
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                ViewBag.Error = "Oturum bulunamadý. Lütfen tekrar giriþ yapýnýz.";
                return RedirectToAction("Login", "Home");
            }
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult SalonEkleme(Salon salon)
        {
            // Model doðrulama kontrolü

            try
            {
                // Yeni salon kaydýný veritabanýna ekleme
                _context.Salons.Add(salon);

                // Deðiþiklikleri veritabanýna kaydetme
                _context.SaveChanges();

                // Baþarý mesajýný TempData ile saklama
                TempData["SuccessMessage"] = "Salon baþarýyla eklendi!";

                // Baþka bir sayfaya veya ayný sayfaya yönlendirme
                return RedirectToAction("AdminPanel");
            }
            catch (Exception ex)
            {
                // Hata durumunda loglama (opsiyonel)
                _logger.LogError("Salon eklenirken bir hata oluþtu: " + ex.Message);

                // Hata mesajýný TempData ile saklama
                TempData["ErrorMessage"] = "Bir hata oluþtu: " + ex.Message;

                // Hata durumunda ayný form sayfasýna geri dönme
                return View(salon);
            }


            // Model geçersizse formu ayný sayfada göster
            return View(salon);
        }  
        public IActionResult IslemEkleme()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            var userRole = HttpContext.Session.GetInt32("UserRole");

            if (userId != null && userRole != null)
            {
                // Sadece adminler bu sayfaya eriþebilir
                if (userRole == 1)
                {
                    ViewBag.SalonList = new SelectList(_context.Salons.ToList(), "SalonId", "SalonAdi");
                ViewBag.Kim = 1;
                    return View();
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                ViewBag.Error = "Oturum bulunamadý. Lütfen tekrar giriþ yapýnýz.";
                return RedirectToAction("Login", "Home");
            }
        }

        [HttpPost]
        [ValidateAntiForgeryToken]


        public IActionResult IslemEkleme(Islem islem)
        {
            ViewBag.SalonList = new SelectList(_context.Salons.ToList(), "SalonId", "SalonAdi");


            try
            {
                // Veritabanýna ekle
                _context.Islems.Add(islem);
                _context.SaveChanges();

                TempData["SuccessMessage"] = "Ýþlem baþarýyla eklendi!";
                return RedirectToAction("AdminPanel");
            }
            catch (Exception ex)
            {
                _logger.LogError("Ýþlem eklenirken bir hata oluþtu: " + ex.Message);
                TempData["ErrorMessage"] = "Bir hata oluþtu: " + ex.Message;
            }


            return View(islem);
        }
        [HttpGet]
        public IActionResult CalisanEkleme()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            var userRole = HttpContext.Session.GetInt32("UserRole");

            if (userId != null && userRole != null)
            {
                // Sadece adminler bu sayfaya eriþebilir
                if (userRole == 1)
                {

                    ViewBag.SalonList = new SelectList(_context.Salons.ToList(), "SalonId", "SalonAdi");
                    ViewBag.IslemList = new SelectList(_context.Islems.ToList(), "IslemId", "IslemAdi");
                    ViewBag.RolList = new SelectList(_context.Rols.ToList(), "RolId", "RolAdi");
                ViewBag.Kim = 1;
                    return View();
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                ViewBag.Error = "Oturum bulunamadý. Lütfen tekrar giriþ yapýnýz.";
                return RedirectToAction("Login", "Home");
            }
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult CalisanEkleme(Calisan calisan)
        {
            ViewBag.SalonList = new SelectList(_context.Salons.ToList(), "SalonId", "SalonAdi");
            ViewBag.IslemList = new SelectList(_context.Islems.ToList(), "IslemId", "IslemAdi");
            ViewBag.RolList = new SelectList(_context.Rols.ToList(), "RolId", "RolAdi");

            try
            {
                // Veritabanýna ekle
                _context.Calisans.Add(calisan);
                _context.SaveChanges();

                TempData["SuccessMessage"] = "Çalýþan baþarýyla eklendi!";
                return RedirectToAction("AdminPanel");
            }
            catch (Exception ex)
            {
                _logger.LogError("Çalýþan eklenirken bir hata oluþtu: " + ex.Message);
                TempData["ErrorMessage"] = "Bir hata oluþtu: " + ex.Message;
            }

            return View(calisan);
        }

        public IActionResult Login(string username, string password)
        {
            user = _context.Calisans
         .FirstOrDefault(u => u.KullaniciAdi == username && u.Sifre == password);

            if (user != null)
            {
                // Kullanýcý bilgilerini oturuma ekle
                HttpContext.Session.SetInt32("UserId", user.CalisanId);
                HttpContext.Session.SetInt32("UserRole", user.RolId);

                // Admin paneline yönlendirme
                if (user.RolId == 1)
                {
                    return RedirectToAction("AdminPanel", "Home");
                }
                return RedirectToAction("Login", "Home");
            }
            else
            {
                ViewBag.Error = "Kullanýcý adý veya þifre hatalý!";
                return View();
            }
        }


        // button eklenecek Laout'a
        public IActionResult Logout()
        {
            HttpContext.Session.Clear(); // Tüm oturum verilerini temizle
                ViewBag.Kim = null;
            return RedirectToAction("Anasayfa", "Home");
        }


        public IActionResult MusteriEkleme()
        {
            return View();
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult MusteriEkleme(Musteri musteri)
        {
            // Model doðrulama kontrolü

            try
            {
                // Yeni Musteri kaydýný veritabanýna ekleme
                _context.Musteris.Add(musteri);

                // Veritabanýna deðiþiklikleri kaydetme
                _context.SaveChanges();

                // Baþarý mesajýný TempData ile saklama
                TempData["SuccessMessage"] = "Rol baþarýyla eklendi!";

                // Rol listeleme veya baþka bir sayfaya yönlendirme
                ViewBag.Kim = 3;

                return RedirectToAction("Login");
            }
            catch (Exception ex)
            {
                // Hata durumunda loglama (opsiyonel)
                _logger.LogError("Rol eklenirken bir hata oluþtu: " + ex.Message);

                // Hata mesajýný TempData ile saklama
                TempData["ErrorMessage"] = "Bir hata oluþtu: " + ex.Message;

                // Hata durumunda ayný form sayfasýna geri dönme
                return View(musteri);
            }


            // Model geçersizse ayný sayfaya geri dön
            return View(musteri);
        }


        public IActionResult RandevuEkleme()
        {
            // Oturum açmýþ kullanýcý var mý kontrol et
            var userId = HttpContext.Session.GetInt32("UserId");

            if (userId == null)
            {
                TempData["ErrorMessage"] = "Lütfen giriþ yapýn!";
                return RedirectToAction("Login"); // Kullanýcýyý giriþ sayfasýna yönlendir
            }

            // Kullanýcý giriþ yapmýþsa, randevu ekleme sayfasýný göster
                ViewBag.Kim = 3;
            return View();
        }


        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult RandevuEkleme(string username, string password)
        {
            try
            {
                // Kullanýcýyý email ve þifreye göre ara
                var user = _context.Musteris
                    .FirstOrDefault(u => u.Email == username && u.MusteriSifre == password);

                if (user != null) // Kullanýcý bulundu
                {
                    ViewBag.Kim = 3;
                    // Oturuma kullanýcý bilgilerini ekle
                    HttpContext.Session.SetInt32("UserId", user.MusteriId);  // Kullanýcý ID'sini sakla
                    HttpContext.Session.SetString("UserName", user.Email);   // Kullanýcý email'ini sakla

                    TempData["SuccessMessage"] = "Baþarýyla giriþ yaptýnýz!";

                    // Giriþ sonrasý yönlendirme
                    return RedirectToAction("RandevuEkleme"); // Giriþ baþarýlýysa randevu ekleme sayfasýna yönlendir
                }
                else
                {
                    TempData["ErrorMessage"] = "Email veya þifre hatalý!";
                    return RedirectToAction("Login"); // Kullanýcýyý tekrar giriþ sayfasýna yönlendir
                }
            }
            catch (Exception ex)
            {
                _logger.LogError($"Randevu alýrken bir hata oluþtu: {ex.Message}");
                TempData["ErrorMessage"] = "Bir hata oluþtu. Lütfen tekrar deneyin.";
                return RedirectToAction("Login"); // Hata durumunda login sayfasýna yönlendirme
            }
        }



        public IActionResult RandevuGoruntuleme()
        {
            // Oturumdan kullanýcý ID'sini al
            var userId = HttpContext.Session.GetInt32("UserId");
            if (userId == null)
            {
                TempData["ErrorMessage"] = "Lütfen giriþ yapýn!";
                return RedirectToAction("Login");
            }

            // Kullanýcýya ait randevularý getir
            var randevular = _context.Randevus
                .Include(r => r.Musteri)
                .Include(r => r.Calisan)
                .Include(r => r.Islem)
                .Where(r => r.MusteriId == userId)
                .ToList();

                ViewBag.Kim = 3;
            return View(randevular);
        }


        public IActionResult RandevuAlma()
        {
            // Ýþlemleri Dropdown için getir
            var islemler = _context.Islems.ToList();
            ViewBag.Islemler = new SelectList(islemler, "IslemId", "IslemAdi");

                ViewBag.Kim = 3;
            return View();
        }


        [HttpPost]
        public IActionResult RandevuAlma(int islemId, int calisanId, DateTime tarih, string saatAraligi)
        {
            // Giriþ yapan kullanýcýnýn kimliðini al
            var userId = HttpContext.Session.GetInt32("UserId");

            if (userId == null)
            {
                ViewBag.Hata = "Lütfen giriþ yapýn.";
                return RedirectToAction("Login");
            }

            // Kullanýcýnýn müþteri ID'sini almak için kullanýcýyý sorgulama
            var musteri = _context.Musteris.FirstOrDefault(m => m.MusteriId == userId.Value);

            if (musteri == null)
            {
                ViewBag.Hata = "Müþteri bilgileri bulunamadý.";
                return RedirectToAction("Login");
            }

            // Çakýþma kontrolü
            var mevcutRandevu = _context.Randevus
                .FirstOrDefault(r => r.CalisanId == calisanId && r.Tarih.Date == tarih.Date && r.SaatAraligi == saatAraligi && r.Onay==true);

            if (mevcutRandevu != null)
            {
                TempData["HataMesaji"] = "Bu saatte çalýþan müsait deðil lütfen baþka bir saat aralýðý seçin.";
                return RedirectToAction("HataMesaji");
            }

            // Yeni randevu ekle
            var yeniRandevu = new Randevu
            {
                MusteriId = musteri.MusteriId, // Müþteri ID'sini kullan
                CalisanId = calisanId,
                IslemId = islemId,
                Tarih = tarih,
                SaatAraligi = saatAraligi,
                Onay = false
            };

            _context.Randevus.Add(yeniRandevu);
            _context.SaveChanges();

            return RedirectToAction("RandevuGoruntuleme");
        }

        // Randevu alýrken çalýþanýn dolu olduðu vakitler
        [HttpGet]
        public IActionResult GetDoluSaatler(int calisanId)
        {
            var doluSaatler = _context.Randevus
                .Where(r => r.CalisanId == calisanId && r.Onay == true)
                .Select(r => new
                {
                    r.Tarih,
                    r.SaatAraligi
                })
                .ToList();

            return Json(doluSaatler);
        }


        public IActionResult HataMesaji()
        {
            return View();
        }

        public IActionResult GetCalisanlar(int islemId)
        {
            var calisanlar = _context.Calisans
                .Where(c => c.IslemId == islemId)
                .Select(c => new
                {
                    calisanId = c.CalisanId,
                    adSoyad = c.AdSoyad
                })
                .ToList();

                ViewBag.Kim = 3;
            return Json(calisanlar);
        }

        [HttpPost]
        public IActionResult SilRandevu(int randevuId)
        {
            var randevu = _context.Randevus.FirstOrDefault(r => r.RandevuId == randevuId);

            if (randevu != null)
            {
                _context.Randevus.Remove(randevu);
                _context.SaveChanges();
                TempData["SuccessMessage"] = "Randevunuz baþarýyla silindi.";
            }
            else
            {
                TempData["ErrorMessage"] = "Randevu bulunamadý.";
            }

            return RedirectToAction("RandevuGoruntuleme");
        }


        public IActionResult TumRandevularýGoruntule()
        {
            var tumRandevular = _context.Randevus
                .Include(r => r.Musteri)  // Müþteri bilgilerini de dahil et
                .Include(r => r.Calisan)  // Çalýþan bilgilerini de dahil et
                .Include(r => r.Islem)    // Ýþlem bilgilerini de dahil et
                .ToList();

                ViewBag.Kim = 1;
            return View(tumRandevular);
        }


        public IActionResult Onayla(int randevuId)
        {
            // Randevuyu veritabanýndan bul
            var randevu = _context.Randevus.FirstOrDefault(r => r.RandevuId == randevuId);

            if (randevu != null)
            {
                // Randevu onayýný deðiþtir
                randevu.Onay = true;

                // Veritabanýnda deðiþiklikleri kaydet
                _context.SaveChanges();
            }


            // Tüm randevularý görüntüle
                ViewBag.Kim = 1;
            return RedirectToAction("TumRandevularýGoruntule");
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
